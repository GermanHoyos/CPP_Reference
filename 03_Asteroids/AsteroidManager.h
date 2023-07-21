#pragma once
#include <vector>
#include <raylib.h>

class Asteroid {
public:
	static int id;
	int myId;
	float x;
	float y;
	float radius;
	float angle;

	Vector2 asteroidCenter;

	Asteroid(float posX, float posY, float r, float angle);

	void moveAsteroid();
	void detectBounds();
	void drawOutline();
	void drawAsteroid();

};

class AsteroidManager { 
public:
	static std::vector<Asteroid> asteroidList;
};

