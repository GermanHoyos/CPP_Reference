#ifndef ANIMATIONFUNCTIONS_H
#define ANIMATIONFUNCTIONS_H
#include "raylib.h" // Include raylib.h here to access Vector2
#include <cmath>

enum AnimTypes {
    EaseIn,
    EaseOut,
    EaseInOut,
    EaseInOutBack
};

// The same function name could be overloaded as long as the return types are unique
// so in cases like this you can use a template (which can create functions or classes)
// as a way to simplify the amount of code you have to right so that a function or a 
// class can accept any type
// template <class T> 
// T playAnimation(T objToAnimate, float currentTime, float animDuration, AnimTypes animationType) {

template <class T> 
T playAnimation(T objToAnimate, float currentTime, AnimTypes animationType, Vector2 startLocation, Vector2 vectorDest, float animRadius) {

    // if (objToAnimate.xy.x <= (vectorDest.x - .01f) && objToAnimate.xy.y <= vectorDest.y)
    // {
    //     objToAnimate.tweenActive = true;
    // } 
    // else 
    // {
    //     objToAnimate.tweenActive = false;
    // }

    // Check if the object is within the specified radius of the vectorDest point.
    float distance = sqrt(pow(startLocation.x - vectorDest.x, 2) + pow(startLocation.y - vectorDest.y, 2));

    if (distance <= animRadius) {
        objToAnimate.tweenActive = true;
    }
    else
    {
        objToAnimate.tweenActive = true;
    }


    if (objToAnimate.tweenActive)
    {
        switch (animationType)
        {
            case EaseIn:
                objToAnimate.xy = easeInApply({10, 10}, {vectorDest.x,vectorDest.y}, currentTime);
                break;
            case EaseOut:
                objToAnimate.xy = easeOutApply({10, 30}, {vectorDest.x, vectorDest.y}, currentTime);
                break;
            default:
                break;
        }
    }

    return objToAnimate;
}


#endif // ANIMATIONFUNCTIONS_H
