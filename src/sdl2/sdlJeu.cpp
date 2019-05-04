#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include "Vect.h"
#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 64;
const int TAILLE_MAP = 50;
const int TAILLE_FENETRE = 1000;
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
    monstre.loadFromFile("./data/image/monster.png",renderer);
    base.loadFromFile("./data/image/base.png",renderer);
	tour.loadFromFile("./data/image/tower.png",renderer);
	coin.loadFromFile("./data/image/coin.png",renderer);
    img_life.loadFromFile("./data/image/life.png", renderer);
    img_upDamage.loadFromFile("./data/image/upDamage.png",renderer);
    img_upPortee.loadFromFile("./data/image/upPortee.png",renderer);
    img_upVitesseAtq.loadFromFile("./data/image/upVitesse.png",renderer);
    img_play.loadFromFile("./data/image/play.png",renderer);
    img_pause.loadFromFile("./data/image/pause.png",renderer);
    emplacement.loadFromFile("./data/image/emplacement.png",renderer);
    
    // FONTS
    font = TTF_OpenFont("./data/font/DejaVuSansCondensed.ttf",50);
    if (font == NULL) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
	}
	font_color.r = 0;font_color.g = 0;font_color.b = 0;
	

    // SONS
  if (withSound)
    {
        sound = Mix_LoadMUS("./data/sound/son.wav");
        if (sound == NULL) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl; SDL_Quit(); exit(1);
        }
    }  
}

sdlJeu::~sdlJeu () {
    if (withSound){
        Mix_FreeMusic(sound);
        Mix_CloseAudio();
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void sdlJeu::affBouton( const Bouton &b){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect v;
    Bouton p = b;
    v.x = p.getPos().getX()+1;
    v.y = p.getPos().getY()+1;
    v.w = p.getTaille().getX()-2;
    v.h = p.getTaille().getY()-2;
    SDL_RenderFillRect( renderer, &v );
    SDL_Surface * text = TTF_RenderText_Solid(font, p.getNom().c_str() ,font_color);
    Image f;
    f.setSurface(text);
	f.loadFromCurrentSurface(renderer);
    SDL_RenderCopy(renderer,f.getTexture(),NULL,&v);
    
    SDL_FreeSurface(text); 
	
}

void sdlJeu::affBouton(const Bouton &b, Image &im){
    SDL_Rect v;
    Bouton p = b;
    v.x = p.getPos().getX();
    v.y = p.getPos().getY();
    v.w = p.getTaille().getX();
    v.h = p.getTaille().getY();
    im.draw(renderer, v.x, v.y, v.w, v.h);
}
void sdlJeu::sdlCircle(const Vect & vec,const int & radius ,const  int & width){
    int radius_min = radius -1- float(width)/2 , radius_max = radius + float(width)/2;
    int x = vec.getX(), y=vec.getY();
    int r ;
    for(int i = x - radius_max  ; i<x+radius_max;i++ ){
        for(int j = y - radius_max  ; j<y+radius_max;j++ ){
             r = (vec-Vect(i,j)).module();
             
             if(r<=radius_max && r >= radius_min)
                SDL_RenderDrawPoint(renderer,i,j);
        }
    }
   
}
void sdlJeu::sdlAff () {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 255, 240, 255);
    SDL_RenderClear(renderer);
    if(jeu.getNiveau() != NULL){
        background.draw(renderer,0,0,1000,1000);
        //jeu.getNiveau()->affiche();
        
        unsigned int nbTourDansNiveau = jeu.getNiveau()->getCarte().tailleTabTour();
        unsigned int nbCheminDansNiveau = jeu.getNiveau()->getCarte().tailleTabChemin();
        Vect v , vv;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        for (unsigned int i = 0; i < nbCheminDansNiveau; i++){//    affiche les chemins
            for( int j = 1 ; j < int(jeu.getNiveau()->getCarte().cheminIndice(i).tailleChemin()) ; j++){
                v = jeu.getNiveau()->getCarte().cheminIndice(int(i)).prochaineEtape(j-1);
                vv = jeu.getNiveau()->getCarte().cheminIndice(int(i)).prochaineEtape(j);
                SDL_RenderDrawLine(renderer,
                                    v.getX()*float(TAILLE_FENETRE)/TAILLE_MAP,
                                    v.getY()*float(TAILLE_FENETRE)/TAILLE_MAP,
                                    vv.getX()*float(TAILLE_FENETRE)/TAILLE_MAP,
                                    vv.getY()*float(TAILLE_FENETRE)/TAILLE_MAP);

                
            }
        }
       
        for (unsigned int i = 0; i < nbTourDansNiveau; i++){//affiche les tours 
            v = jeu.getNiveau()->getCarte().tourIndice(i).getPosition();
            if(jeu.getNiveau()->getCarte().tourIndice(i).getSpawn())tour.draw(renderer,
                v.getX()*float(TAILLE_FENETRE)/TAILLE_MAP - TAILLE_SPRITE/2,
                v.getY()*float(TAILLE_FENETRE)/TAILLE_MAP - TAILLE_SPRITE/2,
                TAILLE_SPRITE,
                TAILLE_SPRITE);
            else emplacement.draw(renderer,
                v.getX()*float(TAILLE_FENETRE)/TAILLE_MAP - TAILLE_SPRITE/2,
                v.getY()*float(TAILLE_FENETRE)/TAILLE_MAP - TAILLE_SPRITE/2,
                TAILLE_SPRITE,
                TAILLE_SPRITE);
        }
        if (jeu.getNiveau()->addrGetCarte()->tailleTabVague() > 0){//affiche les monstres
            for(unsigned int i = 0 ; i < jeu.getNiveau()->getCarte().vagueIndice(0).getVague().size();i++){
                if(jeu.getNiveau()->addrGetCarte()->addrVagueIndice(0)->addrGetIndiceMonstre(i)->getSpawn()){
                    
                    v =jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[i].getPos(); 
                    monstre.draw(renderer,
                        v.getX()*float(TAILLE_FENETRE)/TAILLE_MAP - TAILLE_SPRITE/4,
                        v.getY()*float(TAILLE_FENETRE)/TAILLE_MAP - TAILLE_SPRITE/4,
                        TAILLE_SPRITE/2,
                        TAILLE_SPRITE/2);
                }
            }
        }
        v = jeu.getNiveau()->addrGetCarte()->getBase().getPosition();
        base.draw(renderer,
            (v.getX()*float(TAILLE_FENETRE)/TAILLE_MAP)-TAILLE_SPRITE,
            (v.getY()*float(TAILLE_FENETRE)/TAILLE_MAP)-TAILLE_SPRITE,
            TAILLE_SPRITE*2,
            TAILLE_SPRITE*2);//affiche la base
        //sdlCircle(Vect((v.getX()*float(TAILLE_FENETRE)/TAILLE_MAP),(v.getY()*float(TAILLE_FENETRE)/TAILLE_MAP)),64,3);
        Image f;
        SDL_Rect pos;

        int res;
        int res2;

        if(jeu.tourSelect() != NULL){
            unsigned int nbGoldDegats = jeu.tourSelect()->getAttaque().getDegats();
            unsigned int nbGoldVitesse = 8 * jeu.tourSelect()->getVitAtq();
            unsigned int nbGoldPortee = 2 * jeu.tourSelect()->getPortee();
            sdlCircle(jeu.tourSelect()->getPosition()*float(TAILLE_FENETRE)/TAILLE_MAP,jeu.tourSelect()->getPortee()*float(TAILLE_FENETRE)/TAILLE_MAP,3);

            res = (int)nbGoldDegats;
            res2 = 1;
            while (res >= 10){
                res2 ++ ;
                res = res / 10.0;
            }

            //Affichage du gold dégats
            SDL_Surface * txtGoldDamage= TTF_RenderText_Solid(font,to_string(nbGoldDegats).c_str(),font_color);
            f.setSurface(txtGoldDamage);
            f.loadFromCurrentSurface(renderer);
            pos.x = 70; pos.y = 120; pos.w = 15 * res2; pos.h = 30;
            SDL_RenderCopy(renderer,f.getTexture(),NULL,&pos);
            SDL_FreeSurface(txtGoldDamage);

            unsigned int degatsTour = jeu.tourSelect()->getAttaque().getDegats();
            SDL_Surface * txtDamage = TTF_RenderText_Solid(font, (to_string(degatsTour) + "->" + to_string(degatsTour + 5)).c_str() ,font_color);
            f.setSurface(txtDamage);
            f.loadFromCurrentSurface(renderer);
            pos.x = 70; pos.y = 150; pos.w = 30 * res2; pos.h = 30;
            SDL_RenderCopy(renderer,f.getTexture(),NULL,&pos);
            SDL_FreeSurface(txtDamage);

            res = (int)nbGoldVitesse;
            res2 = 1;
            while (res >= 10){
                res2 ++ ;
                res = res / 10.0;
            }

            //Affichage du gold vitesse
            SDL_Surface * txtGoldSpeed= TTF_RenderText_Solid(font,to_string(nbGoldVitesse).c_str(),font_color);
            f.setSurface(txtGoldSpeed);
            f.loadFromCurrentSurface(renderer);
            pos.x = 70; pos.y = 180; pos.w = 15 * res2; pos.h = 30;
            SDL_RenderCopy(renderer,f.getTexture(),NULL,&pos);
            SDL_FreeSurface(txtGoldSpeed);

            unsigned int vitesseTour = jeu.tourSelect()->getVitAtq();
            string vitTour = to_string(vitesseTour + 0.5);
            SDL_Surface * txtSpeed = TTF_RenderText_Solid(font, (to_string(vitesseTour) + "->" + vitTour.substr(0, vitTour.find(".") + 2)).c_str() ,font_color);
            f.setSurface(txtSpeed);
            f.loadFromCurrentSurface(renderer);
            pos.x = 70; pos.y = 210; pos.w = 30 * res2; pos.h = 30;
            SDL_RenderCopy(renderer,f.getTexture(),NULL,&pos);
            SDL_FreeSurface(txtSpeed);

            res = (int)nbGoldPortee;
            res2 = 1;
            while (res >= 10){
                res2 ++ ;
                res = res / 10.0;
            }

            //Affichage du gold portée
            SDL_Surface * txtGoldPortee= TTF_RenderText_Solid(font,to_string(nbGoldPortee).c_str(),font_color);
            f.setSurface(txtGoldPortee);
            f.loadFromCurrentSurface(renderer);
            pos.x = 70; pos.y = 240; pos.w = 15 * res2; pos.h = 30;
            SDL_RenderCopy(renderer,f.getTexture(),NULL,&pos);
            SDL_FreeSurface(txtGoldPortee);

            unsigned int porteeTour = jeu.tourSelect()->getPortee();
            SDL_Surface * txtPortee = TTF_RenderText_Solid(font, (to_string(porteeTour) + "->" + to_string(porteeTour + 1)).c_str() ,font_color);
            f.setSurface(txtPortee);
            f.loadFromCurrentSurface(renderer);
            pos.x = 70; pos.y = 270; pos.w = 30 * res2; pos.h = 30;
            SDL_RenderCopy(renderer,f.getTexture(),NULL,&pos);
            SDL_FreeSurface(txtPortee);

            affBouton(jeu.renvoieBoutonAmelioration()->at(0), img_upDamage);
            affBouton(jeu.renvoieBoutonAmelioration()->at(2), img_upPortee);
            affBouton(jeu.renvoieBoutonAmelioration()->at(1), img_upVitesseAtq);
        }

        res = jeu.getNiveau()->getOr();

        res2 = 1;
        while (res >= 10){
            res2 ++ ;
            res = res / 10.0;
        }


        img_life.draw(renderer, 0, 0, 60, 60);
        SDL_Surface * text1= TTF_RenderText_Solid(font,to_string(jeu.getNiveau()->addrGetCarte()->getBase().getVie()).c_str(),font_color);
        f.setSurface(text1);
        f.loadFromCurrentSurface(renderer);

        pos.x = 60; pos.y =0; pos.w = 80; pos.h = 60;

        SDL_RenderCopy(renderer,f.getTexture(),NULL,&pos);
        SDL_FreeSurface(text1);


        coin.draw(renderer, 0, 60, 60, 60);
        SDL_Surface * text2 = TTF_RenderText_Solid(font,to_string(jeu.getNiveau()->getOr()).c_str(),font_color);
        f.setSurface(text2);
        f.loadFromCurrentSurface(renderer);
        
        pos.x = 60; pos.y =60; pos.w = 30 * res2; pos.h = 60;
        SDL_RenderCopy(renderer,f.getTexture(),NULL,&pos);
        SDL_FreeSurface(text2);

        
    }
    if (jeu.getPause()){
        affBouton(jeu.getBoutonPause(), img_pause);
        Menu m = jeu.getMenuMap();
        for (unsigned int i = 0 ; i <  m.getTaille() ; i++){
            affBouton(m.getBoutonIndice(i));
        }
    }
    else{
        affBouton(jeu.getBoutonPause(), img_play);
    }

    //for (unsigned int i = 0 ; i < jeu.renvoieBoutonTour()->size();i++)
    //  affBouton(jeu.renvoieBoutonTour()->at(i));

    
	
	
	
    

}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
	bool quit = false;
	int x, y;
    int fps =0;
    Uint32 t = SDL_GetTicks(), nt;
    Uint32 ta = SDL_GetTicks();
    Uint32 tfps = SDL_GetTicks();
    Mix_PlayMusic(sound, -1);
    string backgroundCourrant = "NULL";
    
	// tant que ce n'est pas la fin ...
	while (!quit) {
        
        nt = SDL_GetTicks();
        if(nt-t > 50){
            jeu.actionAuto(float(nt-t));
            t = nt;
        }
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

			else if (events.type == SDL_MOUSEBUTTONUP) {              // Si l'utilisateur à cliqué
				if (events.button.button == SDL_BUTTON_LEFT){
					SDL_GetMouseState(&x, &y);
                    //std::cout << x/TAILLE_SPRITE << " " << y/TAILLE_SPRITE << std::endl;
                    //std::cout << x << " " << y << std::endl;
                    jeu.clique(x,y,TAILLE_SPRITE);
                    if(jeu.getPause()){ 
                        if(jeu.getNiveau() != NULL){
                            jeu.getNiveau()->affiche();
                            string bg = jeu.getImageMap();
                            
                            if(backgroundCourrant != bg) {
                                
                                backgroundCourrant = bg;cout<<backgroundCourrant<<endl;
                                background.loadFromFile(backgroundCourrant.c_str(),renderer);
                            }
                        }
                    }
                    //jeu.tourSelect()->affiche();
				}else{
					x = -1;
					y = -1;
				}
			}
			
		}
       
            
		// on affiche le jeu sur le buffer cach
		if(nt-ta > 1000.0/30.0){sdlAff();fps++;ta = nt;}
        //if(nt-tfps > 1000.0) {cout<<fps<<endl;fps=0;tfps =nt;}
		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}

/*tour:5:4:21:30:0:20
tour:5:4:15:34:0:20
tour:5:4:3:38:0:20
tour:5:4:25:37:0:20
chemin:16.5,10:16.5,20:35,20
chemin:3,10:3,23:11.5,23:11.5,32:35,32
vague:1:2:10/5/0,20/5/0,10/4/0,40/2/0,15/4/0,10/3/0,15/4/0,10/4/0,15/5/0
vague:1:2:20/5/1,20/5/1,20/4/1,50/2/1,25/2/1,10/3/1,15/3/1,10/4/1,15/2/1
vague:1:2:20/5/0,20/5/1,20/4/0,50/2/1,25/2/0,10/3/1,15/3/0,10/4/1,15/2/0
vague:1:2:100/1/0
base:35,30:


tour:5:4:0:0:0:20
tour:5:4:0:48:0:20
tour:5:4:48:48:0:20
tour:5:4:48:0:0:20
chemin:1,1:25,25
vague:1:2:10/5/0
base:1,25:

*/