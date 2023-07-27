#pragma once
#include "raylib_and_all_headers_wrapper.h"

class Npc {
public:
	//Scoped var's
	Vector2 screen = { 800, 600 };
	Vector2 direction;
	float friction = 2.00f;
	float magnitude;
	float magnitudeReducer;
	float finalMagnitude;
	bool radialTrigger = false;

	//Constructor var's
	float radius;
	float rotation = 0.00f;
	Vector2 position;
	Vector2 velocity;
	Texture2D ships;
	
	Npc(float posX, float posY, float velX, float velY, float r, Texture2D ships);

	void moveNpc();
	void detectBounds(); //both virtual and real
	void renderNpc();
	void drawNpc();

};

class NpcManager {
public:
	static std::vector<Npc> npcList;
};