/*
These classes are an attempt to create the same functionality found in
CSS animation keyframes but in C++

 - Durations are in milliseconds
 - The amount of steps are dependent on the paramerter "steps"
 - Possibly use dynamic arrays
 - Possibly use custom tween math
 - Possible use mapping in c++
 
*/

#ifndef EASINGFUNCTIONS_H
#define EASINGFUNCTIONS_H
#include <raylib.h>

// Ease In
float easeIn(float t);
Vector2 easeInApply(Vector2 start, Vector2 end, float t);

// Ease Out
float easeOut(float t);
Vector2 easeOutApply(Vector2 start, Vector2 end, float t);

#endif // EASINGFUNCTIONS_H
