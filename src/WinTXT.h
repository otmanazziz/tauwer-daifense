#ifndef WINTXT_H
#define WINTXT_H


class WinTXT {

private:

    int dimx;       
    int dimy;       
    char* win;      

public:

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

