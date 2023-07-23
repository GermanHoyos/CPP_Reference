#include "BulletManager.h"
#include "AsteroidManager.h"
#include "TimeManager.h"
#include "ParticleManager.h"
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

int Bullet::id = 0;

//Explicitly declared constructor
Bullet::Bullet(float posX, float posY, float r, float angleInput)
 : x(posX), y(posY), radius(r), angle(angleInput), bulletCenter({ x, y }) {
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

void Bullet::moveBullet() {
	//bulletCenter.x++;
	float acceleration = 200.0f;
	float dt = TimeUtils::getDeltaTime();
	float fr = TimeUtils::getFPS();

	bulletCenter.x += acceleration * cosf(angle) * dt;
	bulletCenter.y -= acceleration * sinf(angle) * dt;

}

//this function has 2 valid ways of removing bullets from the vector list
void Bullet::detectBounds() {
	// Conditionals for removal
	if 
	(
		bulletCenter.x < 210 || bulletCenter.x > 800 ||
		bulletCenter.y < 0	 || bulletCenter.y > 600
	) 
	{
		out_of_bounds = true;
	}

	////IMPLEMENTATION 1
	////std::remove_if: This is a standard library algorithm provided by the C++ Standard Template Library (STL). It is used to remove elements that meet a certain condition from a sequence (in this case, a vector). The algorithm takes a range defined by two iterators and a predicate (a function or a lambda) that determines which elements should be removed. 
	//// Mark elements for removal (without actually removing them yet)
	//auto newEnd = std::remove_if(			////"auto" deducts a vector position type automaticly
	//	BulletManager::bulletList.begin(),	////starting range
	//	BulletManager::bulletList.end(),	////ending range
	//	[](const Bullet& bullet) {			////lambda expression  
	//		return bullet.out_of_bounds;
	//	}
	//);

	//// Erase the elements marked for removal // newEnd = vector position
	//BulletManager::bulletList.erase(newEnd, BulletManager::bulletList.end());

	////IMPLEMENTATION 2
	// Remove bullets with out_of_bounds set to true
	for (auto findMe = BulletManager::bulletList.begin(); findMe != BulletManager::bulletList.end(); ) {
		if (findMe->out_of_bounds) {
			findMe = BulletManager::bulletList.erase(findMe);
		}
		else {
			++findMe;
		}
	}
}

void Bullet::detectAsteroids(){
	for (auto findMe = AsteroidManager::asteroidList.begin(); findMe != AsteroidManager::asteroidList.end(); ) {
		//const double epsilon = 0.001;
		double distance = sqrt(
			pow((bulletCenter.x - findMe->position.x), 2) +
			pow((bulletCenter.y - findMe->position.y), 2)
		);
		//(int)findMe->asteroidCenter.x < (int)bulletCenter.x
		if (distance <= findMe->radius + radius) {
			findMe = AsteroidManager::asteroidList.erase(findMe);
			
			for (int i = 0; i < 125; i++){
				Particle::genParticle(bulletCenter.x, bulletCenter.y);
			}

		}
		else {
			++findMe;
		}
	}
}

void Bullet::drawOutline() {
	DrawCircleV(bulletCenter, radius, {255,255,255,255});
	//troubleshoot bullet Id's and various other data
	
	//DrawText(to_string((int)bulletCenter.x).c_str(),bulletCenter.x,bulletCenter.y - 20, 10, GREEN);
	//DrawText(to_string(bulletCenter.x).c_str(), bulletCenter.x, bulletCenter.y - 20, 10, GREEN);

}

void Bullet::drawBullet() {
	moveBullet();
	detectBounds();
	detectAsteroids();
	drawOutline();
}

