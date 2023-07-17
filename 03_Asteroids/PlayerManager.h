//file guards:
#ifndef PLAYERSHIP_H //ifndef = if not defined

#define PLAYERSHIP_H //then go ahead and define playership
#include <raylib.h>
#include <cmath>
#include <string>
#include "TimeManager.h" // Include the necessary header file for TimeUtils

class PlayerShip {
public:
	float x = 400.0f;
	float y = 400.0f;
	float radius = 20.0f;
	float acceleration = 3.0f;
	float friction = 1.00f;
	float angle = 90.0f / 180.0f * PI;
	float accelerationangle;
	float rotation = 0.00f;
	float dt; // delta time, any movement should be multiplied by this so that it stays consistent despite FPS changes
	int fr; // frame rate

	Vector2 shipCenter = {
		x, y
	};

	Vector2 newVector = {
		x = 0, y = 0
	};

	Vector2 vertex_a;

	void getGameTimingValues();
	void drawOutLine();
	void drawAngle();
	void moveShip();
	void drawShip();
};

#endif //end of definition to only be defined once
