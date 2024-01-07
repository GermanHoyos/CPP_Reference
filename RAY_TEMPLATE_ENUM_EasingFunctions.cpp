#include "EasingFunctions.h"

// Ease In -------------------------------------------
float easeIn(float t)
{
    return t * t; // x^2 {0<x<1}
}

Vector2 easeInApply(Vector2 start, Vector2 end, float t)
{
    float factor = easeIn(t); // 0.0 -> 1.0
    float x = start.x + (end.x - start.x) * factor;
    float y = start.y + (end.y - start.y) * factor;
    return {x, y};
}

// Ease Out -------------------------------------------
float easeOut(float t)
{
    return 1 - (1 - t) * (1 - t); //1-(x-1)^2 {0<x<1}
}

Vector2 easeOutApply(Vector2 start, Vector2 end, float t)
{
    float factor = easeOut(t);
    float x = start.x + (end.x - start.x) * factor;
    float y = start.y + (end.y - start.y) * factor;
    return {x, y};
}
