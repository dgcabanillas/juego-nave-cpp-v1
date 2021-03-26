#ifndef C_NAVE
#define C_NAVE

#include <iostream>
#include "Handler.h"
#include "Border.h"

using namespace std;

class Nave {
private:
    const char C1 = char(202);   // ╩
    const char C2 = char(205);   // ═
    const char C3 = char(219);   // █ 
    const char C4 = char(186);   // ║
private:
    int x;
    int y;
    int health;
    int width;
    int height;
    int damage;
    int speed;
    void healthText() {
        if ( health < 0 ) cout << "  ---  ";
        else if ( health < 10 ) cout << "  00" << health << "  ";
        else if ( health < 100 ) cout << "  0" << health << "  ";
        else if ( health < 1000 ) cout << "  " << health << "  ";
        else cout << "  999  ";
    }
public:
    Nave(int _x=0, int _y=0) {
        x = _x;
        y = _y;
        health = 20;
        width = 7;
        height = 3;
        damage = 2;
        speed = 1;
    }
    void draw() {
        gotoxy(x, y);       cout << " " << C4 << "   " << C4 << " ";        // " ║   ║ "          
        gotoxy(x, y+1);     cout << C3 << C1 << C2 << C1 << C2 << C1 << C3; // "█╩═╩═╩█"
        gotoxy(x, y+2);     healthText();
    }
    void erase() {
        gotoxy(x,y);        cout << "       ";
        gotoxy(x,y+1);      cout << "       ";
        gotoxy(x,y+2);      cout << "       ";
    }
    void move() {
        if( kbhit() ) {
            erase();
            char tecla = getch();
            switch( tecla ) {
                case 'a':
                    moveLeft();
                    break;
                case 'd':
                    moveRight();
                    break;
                case 'w':
                    speed++;
                    break;
                case 's':
                    speed--;
                    break;
            }
            draw();
        }
    }
    void shoot() {
        if( kbhit() ) {
            char tecla = getch();
            if( tecla == ' ' ) {
                cout << "F";
            }
        } 
    }
    void moveLeft() { if( x - speed > 0 ) x-=speed; }
    void moveRight() { if( x + speed < Border::width - width ) x+=speed; }
    void showStats() {
        gotoxy(1, 1);   cout << "               ";
        gotoxy(1, 2);   cout << "               ";
        gotoxy(1, 3);   cout << "               ";
        gotoxy(1, 1);   cout << "HEALTH: " << health;
        gotoxy(1, 2);   cout << " SPEED: " << speed;
        gotoxy(1, 3);   cout << "DAMAGE: " << damage;
    }
};

#endif // C_NAVE