#pragma once
#include "raylib_and_all_headers_wrapper.h"

class Player {
public:
	//Scoped var's for testing purposes
	Vector2 screen = { 800, 600 };
	Vector2 direction;
	Vector2 circumferencePoint;
	Vector2 directionShow;
	Vector2 displacement;
	Vector2 circlePoint;
	Vector2 displayDirection1;
	Vector2 displayDirection2;
	Vector2 displayDirection3;
	Vector2 negRngPoint;
	Vector2 posRngPoint;

	float friction = 2.00f;
	float magnitude;
	float magnitudeReducer;
	float finalMagnitude;
	float negRange;
	float posRange;
	float displayAngle1;
	float displayAngle2;
	float displayAngle3;	
	
	bool radialTrigger = false;
	bool lookAtTrigger = false;

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