#include <iostream>
#include <raylib.h>
using namespace std;

int main () {

    const int screenWidth = 1000;
    const int screenHeight = 600;

    class MyCircle {
        double x;
        double y;
        double r;
        string color;

        public:
            MyCircle(double xInit, double yInit, double rInit, string colorInit) 
                : x(xInit), y(yInit), r(rInit), color(colorInit) { /* : = initializer list*/}

        void drawThis () {
            DrawCircle(x,y,r,WHITE);
        }
    };

    //cout << "Hello World" << endl;

    MyCircle circle1 (10.0, 10.0, 10.0, "WHITE");

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);
        //start frame --

        circle1.drawThis();

        //end frame --
        EndDrawing();
    }

    CloseWindow();
    return 0;
}