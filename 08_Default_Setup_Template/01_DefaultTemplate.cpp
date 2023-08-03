#include "raylib_and_all_headers_wrapper.h"
#include "TimeManager.h"
#include "InputManager.h"

using namespace std;

Vector2 angleToRadians(float angle, Vector2 origin, float radius){
	angle = angle * 3.15f / 180; //converted to radians
	Vector2 direction = {(origin.x + radius * cosf(angle)),(origin.y + radius * sinf(angle))};
	return direction;
	//TroubleShoot above with:
	//string dir_str = to_string(direction.x) + " " + to_string(direction.y);
	//DrawText(dir_str.c_str(), 0, 0, 20, GREEN);
}

int main() 
{
Vector2 screen = {800,600};
InitWindow(screen.x, screen.y, "C++ Raylib");

// Textures mus be loaded after the InitWindow and before the while game loop
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
// Test Variables (math tests)
float angle = 0;

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

	//Test functions using circle, take an angle and display it on a circle
	angle++;
	Vector2 origin = {250,300};
	DrawCircleV(origin,50,BLACK);
	Vector2 direction = angleToRadians(angle,origin,50);
	DrawCircleV({direction.x,direction.y},4,GREEN);
	

	//



EndDrawing();}

UnloadTexture(ships);
CloseWindow();
return 0;
}