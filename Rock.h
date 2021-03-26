#ifndef C_ROCK
#define C_ROCK

#include "Handler.h"

class Rock {
private:
private:
    int x;
    int y;
    int hp;
    bool destroy;
    void hpText() {
        if ( hp < 0 ) cout << "* -- *";
        else if ( hp < 10 ) cout << "* 0" << hp << " *";
        else if ( hp < 100 ) cout << "* " << hp << " *";
        else cout << "* 99 *";
    }
public:
    Rock(int x, int y, int hp){
        Rock::x = x;
        Rock::y = y;
        Rock::hp = hp;
        Rock::destroy = false;
    }
    void draw() {
        gotoxy(x, y);       cout << " **** ";            
        gotoxy(x, y+1);     hpText();   
        gotoxy(x, y+2);     cout << " **** ";
    }
    void erase() {
        gotoxy(x,y);        cout << "       ";
        gotoxy(x,y+1);      cout << "       ";
        gotoxy(x,y+2);      cout << "       ";
    }
    void move() {
        
    }
};

#endif // C_ROCK