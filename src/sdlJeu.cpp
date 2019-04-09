#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include "Vect.h"
#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 25;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
	SDL_FreeSurface(surfaceCorrectPixelFormat);
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return texture;}

void Image::setSurface(SDL_Surface * surf) {surface = surf;}

// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu () {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;SDL_Quit();exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

	

    // Creation de la fenetre
    window = SDL_CreateWindow("Tauwer Daifense", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_SHOWN );
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    monstre.loadFromFile("monster.png",renderer);
    base.loadFromFile("base.png",renderer);
	tour.loadFromFile("tower.png",renderer);

    // FONTS
    font = TTF_OpenFont("DejaVuSansCondensed.ttf",50);
    if (font == NULL) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
	}
	font_color.r = 0;font_color.g = 0;font_color.b = 0;
	

    // SONS
    if (withSound)
    {
        sound = Mix_LoadWAV("son.wav");
        if (sound == NULL) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl; SDL_Quit(); exit(1);
        }
    }
}

sdlJeu::~sdlJeu () {
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::sdlAff () {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 255, 240, 255);
    SDL_RenderClear(renderer);

	
	unsigned int nbTourDansNiveau = jeu.getNiveau()->getCarte().tailleTabTour();
	unsigned int nbCheminDansNiveau = jeu.getNiveau()->getCarte().tailleTabChemin();
	Vect v , vv;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	for (unsigned int i = 0; i < nbCheminDansNiveau; i++){
		for( int j = 1 ; j < int(jeu.getNiveau()->getCarte().cheminIndice(i).tailleChemin()) ; j++){
			v = jeu.getNiveau()->getCarte().cheminIndice(int(i)).prochaineEtape(j-1);
			vv = jeu.getNiveau()->getCarte().cheminIndice(int(i)).prochaineEtape(j);
			SDL_RenderDrawLine(renderer,
                                  v.getX()*TAILLE_SPRITE+TAILLE_SPRITE/2,
                                 v.getY()*TAILLE_SPRITE+TAILLE_SPRITE/2,
                                  vv.getX()*TAILLE_SPRITE+TAILLE_SPRITE/2,
                                  vv.getY()*TAILLE_SPRITE+TAILLE_SPRITE/2);

			
		}
	}
	
	for (unsigned int i = 0; i < nbTourDansNiveau; i++){
		v = jeu.getNiveau()->getCarte().tourIndice(i).getPosition();
		tour.draw(renderer,v.getX()*TAILLE_SPRITE,v.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
	}
	if (jeu.getNiveau()->addrGetCarte()->tailleTabVague() > 0){
		for(unsigned int i = 0 ; i < jeu.getNiveau()->getCarte().vagueIndice(0).getVague().size();i++){
			if(jeu.getNiveau()->addrGetCarte()->addrVagueIndice(0)->addrGetIndiceMonstre(i)->getSpawn()){
				
				v =jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[i].getPos(); 
				monstre.draw(renderer,v.getX()*TAILLE_SPRITE,v.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
			}
		}
	}
	v = jeu.getNiveau()->addrGetCarte()->getBase().getPosition();
	base.draw(renderer,v.getX()*TAILLE_SPRITE,v.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
	
	
	font_vie.setSurface(TTF_RenderText_Solid(font,("Vie :"+to_string(jeu.getNiveau()->addrGetCarte()->getBase().getVie())).c_str(),font_color));
	font_vie.loadFromCurrentSurface(renderer);
	font_or.setSurface(TTF_RenderText_Solid(font,("Or : "+to_string(jeu.getNiveau()->getOr())).c_str(),font_color));
	font_or.loadFromCurrentSurface(renderer);
	
	SDL_Rect pos;
    pos.x = 0;pos.y =0 ;pos.w = 100;pos.h = 30;
    SDL_RenderCopy(renderer,font_vie.getTexture(),NULL,&pos);
	pos.x = 0;pos.y =40 ;pos.w = 100;pos.h = 30;
	SDL_RenderCopy(renderer,font_or.getTexture(),NULL,&pos);
	
	
	
	
    // Afficher les sprites des murs et des pastilles
	/*for (x=0;x<ter.getDimX();++x)
		for (y=0;y<ter.getDimY();++y)
			if (ter.getXY(x,y)=='#')
				im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
			else if (ter.getXY(x,y)=='.')
				im_pastille.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite de Pacman
	im_pacman.draw(renderer,pac.getX()*TAILLE_SPRITE,pac.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite du Fantome
	im_fantome.draw(renderer,fan.getX()*TAILLE_SPRITE,fan.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 270;positionTitre.y = 49;positionTitre.w = 100;positionTitre.h = 30;
    SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);*/
	
	
	
	/*


	win.clear();
	for( int i = 0 ; i < 40 ; i++) for( int j = 0 ; j < 40 ; j++)win.print(i,j,'.');
	for (unsigned int i = 0; i < nbTourDansNiveau; i++){
		v = jeu.getNiveau()->getCarte().tourIndice(i).getPosition();
		//std::cout << "Coordonnees de la tour " << i + 1 << ".";
		win.print(v.getX(), v.getY(), 'T');
	}

	for (unsigned int i = 0; i < nbCheminDansNiveau; i++){
		for( int j = 0 ; j < int(jeu.getNiveau()->getCarte().cheminIndice(i).tailleChemin()) ; j++){
			v = jeu.getNiveau()->getCarte().cheminIndice(int(i)).prochaineEtape(j);

		//std::cout << "Coordonnees de la tour " << i + 1 << ".";
		win.print(v.getX(), v.getY(), 'X');
		}
	}
	if (jeu.getNiveau()->addrGetCarte()->tailleTabVague() > 0){
		for(unsigned int i = 0 ; i < jeu.getNiveau()->getCarte().vagueIndice(0).getVague().size();i++){
			if(jeu.getNiveau()->addrGetCarte()->addrVagueIndice(0)->addrGetIndiceMonstre(i)->getSpawn()){
				
				v =jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[i].getPos(); 
				win.print(v.getX(), v.getY(), 'M');
			}
		}
	}
	v = jeu.getNiveau()->addrGetCarte()->getBase().getPosition();
	win.print(v.getX(), v.getY(),'B');
	win.draw(); 
	std::cout<<std::endl;
	jeu.getNiveau()->affiche();*/

}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
	bool quit = false;
	int x, y;
    int fps =0;
    Uint32 t = SDL_GetTicks(), nt;
    Uint32 ta = SDL_GetTicks();
    Uint32 tfps = SDL_GetTicks();
	// tant que ce n'est pas la fin ...
	while (!quit) {

        nt = SDL_GetTicks();
       

		// tant qu'il y a des evenements  traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
				switch (events.key.keysym.scancode) {
				case SDL_SCANCODE_UP:
					
					break;
				case SDL_SCANCODE_DOWN:
					
					break;
				case SDL_SCANCODE_LEFT:
					
					break;
				case SDL_SCANCODE_RIGHT:
					
					break;
                case SDL_SCANCODE_ESCAPE:
                case SDL_SCANCODE_Q:
                    quit = true;
                    break;
				default: break;
				}
				
			}

			else if (events.type == SDL_MOUSEBUTTONDOWN) {              // Si l'utilisateur à cliqué
				if (events.button.button == SDL_BUTTON_LEFT){
					SDL_GetMouseState(&x, &y);
				}else{
					x = -1;
					y = -1;
				}
			}
			
		}
       jeu.actionAuto(float(nt-t), x, y);
            t = nt;
		// on affiche le jeu sur le buffer cach
		if(nt-ta > 1000.0/60.0){sdlAff();fps++;ta = nt;}
        if(nt-tfps > 1000.0) {cout<<fps<<endl;fps=0;tfps =nt;}
		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}
