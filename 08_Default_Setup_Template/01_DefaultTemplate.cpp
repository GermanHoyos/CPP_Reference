#include "raylib_and_all_headers_wrapper.h"
#include "TimeManager.h"
#include "InputManager.h"

using namespace std;

Vector2 angleToDirection(float angle, Vector2 origin, float radius){
	//only convert to radians below if not already converted
	angle = angle * 3.14f / 180; //converted to radians
	Vector2 direction = {(origin.x + radius * cosf(angle)),(origin.y + radius * sinf(angle))};
	return direction;
	//TroubleShoot above with:
	//string dir_str = to_string(direction.x) + " " + to_string(direction.y);
	//DrawText(dir_str.c_str(), 0, 0, 20, GREEN);
}

float directionToAngle(Vector2 origin ,Vector2 direction) {
	//remember y is down so convert to conventional : (origin.y - direction.y,direction.x - origin.x)
	//         90
    //         |
    //  180 -------- 0     
    //         |
    //        270
	float angle = atan2(origin.y - direction.y,direction.x - origin.x) * 180 / PI;
	if (angle < 0)
		angle += 360;
	string angle_str = to_string(angle);
	DrawText(angle_str.c_str(), origin.x - 50, origin.y - 75, 20, GREEN);
	return angle;
}


//easeIn
float easeIn(float t) {
	return t * t;
}
Vector2 easeInApply(Vector2 start, Vector2 end, float t) {
	float factor = easeIn(t);
	float x = start.x + (end.x - start.x) * factor;
	float y = start.y + (end.y - start.y) * factor;
	Vector2 xy_returned = {x,y};
	return xy_returned;
}



int main() 
{
Vector2 screen = {800,600};
InitWindow(screen.x, screen.y, "C++ Raylib");

// Textures must be loaded after the InitWindow and before the while game loop
Texture2D ships = LoadTexture("BgLilgShips.png");
int textureW = ships.width / 2; //split the image into 2 equal parts
int textureH = ships.height;
// Source rectangle (part of the texture to use for drawing)
Rectangle sourceRec = { 0.0f, 0.0f, (float)textureW, (float)textureH };
// Destination rectangle (screen rectangle where drawing part of texture)
Rectangle destRec = { 60, screen.y / 2.0f, textureW * 5.0f, textureH * 5.0f };
// Origin of the texture (rotation/scale point), it's relative to destination rectangle size
Vector2 origin = { (float)textureW * 5.0f  / 2, (float)textureH * 5.0f / 2 };
// Change this to rotate textures
int rotation = 0;

// black circle:
float angle = 0;

// easeIn
float t = 0.0f;
Vector2 position1 = {500, 300};

SetTargetFPS(60);
while (WindowShouldClose() == false) {
	BeginDrawing();
	ClearBackground({29,43,83,225});
	// Time mechanics
	TimeUtils::displaySystemTime();	
	//Input mechanics
	InputUtils::printKey();

	// Draw object and move object
	DrawTexturePro(ships, sourceRec, destRec, origin, (float)rotation, WHITE);
	rotation++;

	//black circle:
	//Test functions using circle, take an angle and display it on a circle
	angle++;
	Vector2 origin = {250,300};
	DrawCircleV(origin,50,BLACK);
	Vector2 direction = angleToDirection(angle,origin,50);
	DrawCircleV({direction.x,direction.y},4,GREEN);
	directionToAngle(origin,direction);

	//easeIn
	DrawRectangleV(position1,{10,10},GREEN);
	Vector2 endPosition1 = {750,300};
	float animationSpeedFactor = 0.05f;
	if (t <= 1.0f) {
		position1 = easeInApply(position1, endPosition1, t);
		t += animationSpeedFactor * TimeUtils::getDeltaTime();
	}
	
	


EndDrawing();}

UnloadTexture(ships);
CloseWindow();
return 0;
}