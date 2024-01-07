#include <iostream>
#include <raylib.h>
using namespace std;
#include "EasingFunctions.h"
#include "PlayAnimations.h"

class MyCircle
{
    public:
        Vector2 xy;
        //Vector2 startLocation; //animation start location
        double r;
        string color;
        bool tweenActive = false;
        //animationStart
        //animationEnd
        //animationIteration
        //animationName
        //animationElapsedTime

    public:
        MyCircle(Vector2 xyInit, double rInit, string colorInit)
            : xy(xyInit), r(rInit), color(colorInit)
        { 
            /* initializer list */
        }

        void drawThis()
        {
            DrawCircleV(xy, r, WHITE);
        }
};

int main()
{

    const int screenWidth = 1000;
    const int screenHeight = 600;
    float currentTime = 0.0;



    // cout << "Hello World" << endl;

    MyCircle circle1({10,10}, 10.0, "WHITE");
    MyCircle circle2({10,30}, 10.0, "WHITE");

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        // start frame --
        currentTime += GetFrameTime(); // Get time in seconds for last frame drawn (delta time)
        
        circle1.drawThis();
        circle1 = playAnimation(circle1, currentTime, EaseIn, {10,10}, {600,10}, 6);

        circle2.drawThis();
        circle2 = playAnimation(circle2, currentTime, EaseOut, {10,30}, {600,30}, 6);

        // end frame --
        EndDrawing();
    }

    CloseWindow();
    return 0;
}






















        //All of the below produce the same result
            //circle1.xy = { ++circle1.xy.x, circle1.xy.y };
            //circle1.xy = { x: ++circle1.xy.x, y : circle1.xy.y };
            //circle1.xy.x++;



        //circle1.xy = easeInApply({10,10},{100,10},(currentTime / 1.));