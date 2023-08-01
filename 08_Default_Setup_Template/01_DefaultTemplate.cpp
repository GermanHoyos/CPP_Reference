#include "raylib_and_all_headers_wrapper.h"
#include "TimeManager.h"
#include "InputManager.h"

using namespace std;

//Test functions
Vector2 angToRadiansDirection(float angle) {
	Vector2 direction = { cosf(angle), sin(angle) };
	return direction;
};

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

	//Test functions using circle
	Vector2 direction;
	//direction = angToRadiansDirection(75);
	//float angle = 0;
	angle++;
	float angleToRad = angle * 3.15 / 180;
	direction.x = 250 + 50 * cosf(angleToRad);
	direction.y = 300 - 50 * sinf(angleToRad);
	string dir_str = to_string(direction.x) + " " + to_string(direction.y);
	DrawText(dir_str.c_str(),screen.x / 2, 0, 20, GREEN);
	DrawCircleV({250, 300},50,BLACK);
	DrawCircleV({direction.x,direction.y},4,GREEN);




EndDrawing();}

UnloadTexture(ships);
CloseWindow();
return 0;
}