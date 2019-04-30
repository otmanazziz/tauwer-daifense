#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Jeu.h"

/**
    @brief Class Image
    Classe d'Image, permettant de créer une image avec SDL2
*/
class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

public:
    /**
        @brief Constructeur par défaut: Image
        Permet de créer l'image par défaut
        @code
            Image i
        @endcode
    */   
    Image () ;
    /**
        @brief Procédure: loadFromFile
        Permet de charger une image à partir d'un fichier
        @param Chaîne de caractère filename,SDL_Renderer renderer
        @code
            i2.loadFromFile(filename, renderer);
        @endcode    
    */
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    /**
        @brief Procédure: loadFromCurrentSurface
        Permet de charger texture d'une surface
        @param SDL_Renderer renderer
        @code
            i2.loadFromCurrentSurface(renderer);
        @endcode    
    */
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    /**
        @brief Procédure: draw
        Permet de dessiner l'image 
        @param SDL_Renderer renderer, Entier x, Entier y,Entier w, Entier h)
        @code
            i2.draw(renderer, x, y, w, h);
        @endcode    
    */
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    /**
        @brief Fonction: getTexture
        Permet de retourner la texture de l'image
        @return SDL_Texture texture
        @code
            i2->getTexture();
        @endcode    
    */
    SDL_Texture * getTexture() const;
     /**
        @brief Procédure: setSurface
        Permet de modifier la surface
        @param SDL_Surface surf
        @code
            i2.setSurface(surf);
        @endcode    
    */
    void setSurface(SDL_Surface * surf);
};




/**
    @brief Class sldJeu
    Classe de sdlJeu, permettant d'afficher le jeu en SDL 
*/
class sdlJeu {

private :

	Jeu jeu ; 

    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    SDL_Color font_color;

    Mix_Chunk * sound;
    bool withSound;

    Image tour;
    Image emplacement;
	Image base;
	Image monstre;
    Image coin;
    Image img_life;
    Image img_upDamage;
    Image img_upPortee;
    Image img_upVitesseAtq;
    Image img_play;
    Image img_pause;
    Image background;


public :

    /**
        @brief Constructeur par défaut: sdlJeu
        Permet de créer la sdl du jeu par défaut
        @code
            sdlJeu sj;
        @endcode
    */  
    sdlJeu ();
    /** 
        @brief Destructeur
        Permet de détruire la sdl du jeu

    */
    ~sdlJeu ();
    /**
        @brief Procédure: sdlBoucle
        Permet de tout garder tant que ce n'est pas la fin
        @code
            sj.sdlBoucle();
        @endcode    
    */
   void affBouton( const Bouton &b);
   void affBouton(const Bouton &b, Image &im);
    void sdlBoucle ();
    /**
        @brief Procédure: sdlAff
        Permet de remplir l'écran
        @code
            sj.sdlAff();
        @endcode    
    */
    void sdlAff ();

};

#endif
