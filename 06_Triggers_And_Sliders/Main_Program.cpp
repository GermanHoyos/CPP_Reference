// 06_Triggers_And_Sliders.cpp : This file contains the 'main' function. Program execution begins and ends there.
using namespace std;
#include "raylib_and_all_headers_wrapper.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "PlayerManager.h"
#include "TextureManager.h"



int main()
{
	Vector2 screen = { 800,600 };
	InitWindow(screen.x, screen.y, "C++ Raylib");

	// Textures mus be loaded after the InitWindow and before the while game loop
	Texture2D ships = LdTextures::returnPlayer();

	// Test instantiations
	Player player(200.0f,200.0f,0.0f,0.0f,50.0f,ships);

	// Begin main game loop and set FPS
	SetTargetFPS(60);
	while (WindowShouldClose() == false) {
		
		// Generate drawing context and clear screen after every loop
		BeginDrawing();
		ClearBackground({ 29,43,83,225 });

		// Time mechanics
		TimeUtils::displaySystemTime();

		// Input mechanics
		InputUtils::printKey();
		
		// Test code
		//DrawTexturePro(ships, sourceRec, destRec, origin, (float)rotation, WHITE);
		//rotation++;
		player.drawPlayer();






		EndDrawing();
	}

	//UnloadTexture(ships);
	CloseWindow();
	return 0;
}

