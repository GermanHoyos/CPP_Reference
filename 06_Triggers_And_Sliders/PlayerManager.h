#pragma once
#include "raylib_and_all_headers_wrapper.h"

class Player {
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
	Vector2 velocity; //represents both speed and direction, but updating this you can simulate movement
	Texture2D ships;
	

	Player(float posX, float posY, float velX, float velY, float r, Texture2D ships);

	void movePlayer();
	void detectBounds(); //both virtual and real
	void renderPlayer();
	void drawPlayer();

};

class PlayerManager {
public:
	static std::vector<Player> playerList;
};