#include "AsteroidManager.h"
#include "TimeManager.h"
#include <string>
#include <algorithm>
using namespace std;

int Asteroid::id = 0;

//Explicitly declared constructor
Asteroid::Asteroid(float posX, float posY, float r, float angleInput)
	: x(posX), y(posY), radius(r), angle(angleInput), asteroidCenter({ x, y }) {
	myId = id++;
	//WHY is the first bullet 0?
	/*
	Assign myId in the constructor: myId = id++ (myId = 0, id = 1).
	next myId will be 1

	OR IF ++id;

	Assign myId in the constructor: myId = ++id (id = 1, myId = 1). next
	myId will be 2

	*/
}
void Asteroid::moveAsteroid(){
  //implement angles such that it travels inward from all 4 walls
	float acceleration = 100.0f;
	float dt = TimeUtils::getDeltaTime();
	float fr = TimeUtils::getFPS();

	asteroidCenter.x += acceleration * cosf(angle) * dt;
	asteroidCenter.y -= acceleration * sinf(angle) * dt;
}

void Asteroid::detectBounds(){
  //iether remove asteroid from game upon wall hit or respawn on oposing sides		
	if (asteroidCenter.x < 240) {
		asteroidCenter.x = 800;
	};
	if (asteroidCenter.y < 0) {
		asteroidCenter.y = 600;
	};
	if (asteroidCenter.x > 800) {
		asteroidCenter.x = 240;
	};
	if (asteroidCenter.y > 600) {
		asteroidCenter.y = 0;
	};
}

void Asteroid::drawOutline(){
	DrawCircleV(asteroidCenter, radius, WHITE);
	//DrawText(to_string((int)asteroidCenter.x).c_str(), asteroidCenter.x, asteroidCenter.y - 20, 10, GREEN);
}

void Asteroid::drawAsteroid(){
	moveAsteroid();
	detectBounds();
	drawOutline();
}
