// 06_Triggers_And_Sliders.cpp : This file contains the 'main' function. Program execution begins and ends there.
using namespace std;
#include "raylib_and_all_headers_wrapper.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "PlayerManager.h"
#include "NpcManager.h"
#include "TextureManager.h"

vector<Player> PlayerManager::playerList;
vector<Npc>	NpcManager::npcList;

void radialTriggerChecks(Player& player, vector<Npc>& npcList){
	for (Npc& npc : NpcManager::npcList){
		double distBetweenCenters = sqrt(
			pow((player.position.x - npc.position.x),2) +
			pow((player.position.y - npc.position.y),2)
		);
		
		if (distBetweenCenters <= (player.radius * 3) + (npc.radius)){
			player.radialTrigger = true;
			npc.radialTrigger = true;
		} else {
			player.radialTrigger = false;
			npc.radialTrigger = false;
		}
	}
}

int main()
{
	Vector2 screen = { 800,600 };
	InitWindow(screen.x, screen.y, "C++ Raylib");

	// Textures mus be loaded after the InitWindow and before the while game loop
	Texture2D ships = LdTextures::returnPlayer();

	// Test instantiations
	// Player player(200.0f,200.0f,0.0f,0.0f,50.0f,ships);
	// Npc npc(500.0f,200.0f,0.0f,0.0f,50.0f,ships);
	PlayerManager::playerList.emplace_back(200.0f, 200.0f, 0.0f, 0.0f, 50.0f, ships);
	NpcManager::npcList.emplace_back(500.0f, 200.0f, 0.0f, 0.0f, 50.0f, ships);

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
		
		// Draw All objects stored in lists
		for (Player& player : PlayerManager::playerList){
			player.drawPlayer();
		}
		for (Npc& npc : NpcManager::npcList){
			npc.drawNpc();
		}

		// Check for radial triggers
		radialTriggerChecks(PlayerManager::playerList[0], NpcManager::npcList);




		EndDrawing();
	}

	//UnloadTexture(ships);
	CloseWindow();
	return 0;
}

