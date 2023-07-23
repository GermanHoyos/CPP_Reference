#pragma once
#include <vector>
#include <raylib.h>

class Asteroid {
public:
	static int id;
	int myId;
	float radius;
	Vector2 position;
	Vector2 velocity; //represents both speed and direction, but updating this you can simulate movement

	Asteroid(float posX, float posY, float velX, float velY, float r);

	void moveAsteroid();
	void detectBounds();
	void drawOutline();
	void drawAsteroid();

};
 
class AsteroidManager { 
public:
	static std::vector<Asteroid> asteroidList;
};

