#ifndef WINTXT_H
#define WINTXT_H

/**
    @brief Class WinTXT
    Classe WinTXT, permettant de gérer l'affichage
*/
class WinTXT {

private:

    int dimx;       
    int dimy;       
    char* win;      

public:
    ~WinTXT();
    WinTXT (int dx, int dy);
    void clear (char c=' ');
    void print (int x, int y, char c);
    void print (int x, int y, char* c);
    void draw (int x=0, int y=0);
    void pause();
    char getCh();

};

void termClear ();

#endif

