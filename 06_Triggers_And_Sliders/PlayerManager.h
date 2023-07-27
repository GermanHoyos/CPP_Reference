#pragma once
#include "raylib_and_all_headers_wrapper.h"

class Player {
public:
	
	float radius;
	Vector2 position;
	Vector2 velocity; //represents both speed and direction, but updating this you can simulate movement
	Texture2D ships;
	float rotation = 0.00f;

	Player(float posX, float posY, float velX, float velY, float r, Texture2D ships);

	void movePlayer();
	void detectBounds(); //both virtual and real
	void renderPlayer();
	void drawPlayer();

};