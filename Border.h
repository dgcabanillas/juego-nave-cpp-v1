#ifndef C_Border
#define C_Border

#include <iostream>
#include "Handler.h"

using namespace std;

class Border {
private:
    static const char C1 = char(186);  // ║
    static const char C2 = char(205);  // ═
    static const char C3 = char(201);  // ╔
    static const char C4 = char(200);  // ╚
    static const char C5 = char(187);  // ╗
    static const char C6 = char(188);  // ╝
public:
    static int width;
    static int height;
public:
    //Border() = default;
    static void draw() {
        gotoxy(0, 0);
        for( int i=0; i<height; i++ ) {
            for( int j=0; j<width; j++ ) {
                if( i == 0 && j == 0 ) cout << C3;
                else if( i == 0 && j == width-1 ) cout << C5;
                else if( i == height-1 && j == 0 ) cout << C4;
                else if( i == height-1 && j == width-1 ) cout << C6;
                else if( i == 0 || i == height-1 ) cout << C2;
                else if( j == 0 || j == width-1 ) cout << C1;
                else cout << " ";
            }
            cout << endl;
        }
    }
};

int Border::width = 0;
int Border::height = 0;

#endif // C_Border