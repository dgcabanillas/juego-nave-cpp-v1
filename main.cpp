#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Handler.h"
#include "Border.h"
#include "Nave.h"
#include "Bullet.h"
#include "Rock.h"

using namespace std;

int main() {
    hideCursor();

    Border border = Border();
    Nave nave = Nave(45, 28);
    bool gameOver = false;

    Rock rock_1 = Rock(22, 14, 25);
    Rock rock_2 = Rock(8, 6, 8);
    Rock rock_3 = Rock(45, 2, 12);
    Rock rock_4 = Rock(72, 12, 3);

    
    Bullet bullet_1 = Bullet(48, 23, 20);
    Bullet bullet_2 = Bullet(48, 20, 20);
    Bullet bullet_3 = Bullet(48, 17, 20);
    
    Border::width = 100;
    Border::height = 32;
    Border::draw();
    nave.draw();

    rock_1.draw();
    rock_2.draw();
    rock_3.draw();
    rock_4.draw();

    bullet_1.draw();
    bullet_2.draw();
    bullet_3.draw();
    while( !gameOver ) {
        nave.showStats();
        nave.move();
        nave.shoot();
        Sleep(100);
    }
    return 0;
}