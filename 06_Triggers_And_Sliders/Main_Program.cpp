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
	// The following is direction agnostic and only produces a scalar value for distances
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

void lookAtTriggerChecks(Player& player, vector<Npc>& npcList){
	// To get "normal" or "collision normal" from point a to point b then b - a.
	// Let player = a and Npc (target) = b
	
	for (Npc& npc : NpcManager::npcList){

		// The below "collision normal" may not be needed for lookat trigger mechanics
		Vector2 normal = {
			npc.position.x - player.position.x,
			npc.position.y - player.position.y
		};
		
		// Get the distance between the 2 centers
		double distBetweenCenters = sqrt(
			pow((player.position.x - npc.position.x), 2) +
			pow((player.position.y - npc.position.y), 2)
		);

		// Calculate the direction Vector from the center of player to npc		
		Vector2 direction = {
			(npc.position.x - player.position.x) / distBetweenCenters,
			(npc.position.y - player.position.y) / distBetweenCenters
		};

		// Calculate the desired intersection points where the above line
		// intersects with the players and npc 'radii'
		Vector2 playerIntersection = {
			(player.position.x + direction.x * (player.radius * 3)),
			(player.position.y + direction.y * (player.radius * 3))
		};
		Vector2 npcIntersection = {
			(npc.position.x - direction.x * (npc.radius)),
			(npc.position.y - direction.y * (npc.radius))
		};
		// Draw the Intersections
		DrawCircleV(playerIntersection,4,GREEN);
		DrawCircleV(npcIntersection,4,GREEN);

		// Set look at trigger state to true if playerIntersection is within view scope
		// defined in internal player scope. ATAN2 expects the the cords fed to it to be based
		// on an origin of (0,0) in relation to the object, so just feeding negRngPoint and
		// posRngPoint to the ATAN2	will result in incorrect coords since these values are
		// created such that they are at some point on the radius
		// Step1: get angle equiv of "negRange" scope view
		float negScopeViewAngle = atan2(player.negRngPoint.x - player.position.x, player.negRngPoint.y - player.position.y) * RAD2DEG;
		// Step2: get angle equiv of "posRange" scope view
		float posScopeViewAngle = atan2(player.posRngPoint.x - player.position.x, player.posRngPoint.y - player.position.y) * RAD2DEG;
		// Convert negative angles to positive by adding 360 degrees
		if (negScopeViewAngle < 0) {
			negScopeViewAngle += 360.0f;
		}
		if (posScopeViewAngle < 0) {
			posScopeViewAngle += 360.0f;
		}
		// Step3: get angle equive of playerIntersection
		//float playerIntAngle = atan2(playerIntersection.x,playerIntersection.y); //RETURNS RADIANS
		float playerIntAngle = atan2(playerIntersection.x - player.position.x, playerIntersection.y - player.position.y) * RAD2DEG;
		// Convert negative angles to positive by adding 360 degrees
		if (playerIntAngle < 0) {
			playerIntAngle += 360.0f;
		}
		// Step4: create a conditional that checks if intersection is within defined range
		if (playerIntAngle > negScopeViewAngle && playerIntAngle < posScopeViewAngle){
			DrawText("I SEE YOU!",player.position.x + 8,player.position.y - 70,20,RED);
			player.lookAtTrigger = true;
		} else {
			player.lookAtTrigger = false;
		}
		string playerIntAngle_str = to_string((int)playerIntAngle);
		string negScopeViewAngle_str = to_string((int)negScopeViewAngle);
		string posScopeViewAngle_str = to_string((int)posScopeViewAngle);
		DrawText(playerIntAngle_str.c_str(),playerIntersection.x + 5,playerIntersection.y + 5, 5, RED);
		DrawText(negScopeViewAngle_str.c_str(), player.negRngPoint.x + 5, player.negRngPoint.y + 5, 5, RED);
		DrawText(posScopeViewAngle_str.c_str(), player.posRngPoint.x + 5, player.posRngPoint.y + 5, 5, RED);
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
		lookAtTriggerChecks(PlayerManager::playerList[0], NpcManager::npcList);



		EndDrawing();
	}

	//UnloadTexture(ships);
	CloseWindow();
	return 0;
}

