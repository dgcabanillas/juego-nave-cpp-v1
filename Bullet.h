#ifndef C_BULLET
#define C_BULLET

#include "Handler.h"

class Bullet {
private:
    const char C1 = char(158);
private:
    int x;
    int y;
    int damage;
    bool destroy;
public:
    Bullet(int x, int y, int damage){
        Bullet::x = x;
        Bullet::y = y;
        Bullet::damage = damage;
        Bullet::destroy = false;
    }
    void draw() {
        gotoxy(x, y);   cout << C1;
    }
    void move() {
        gotoxy(x, y);   cout << " ";
        if( y-1 > 1 ) {
            y--;
            draw();
        } else {
            destroy = true;
        }
    }
};

#endif // C_BULLET
