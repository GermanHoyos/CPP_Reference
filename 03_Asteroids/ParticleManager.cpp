#include "ParticleManager.h"
#include "TimeManager.h"
#include <string>
#include <algorithm>
using namespace std;

int Particle::id = 0;

//Explicitly declared constructor
Particle::Particle(float posX, float posY, float r, float angleInput)
	: x(posX), y(posY), radius(r), angle(angleInput), particleCenter({ x, y }) {
	myId = id++;
}

void Particle::moveParticle(){
	//implement angles such that it travels inward from all 4 walls
	float acceleration = 100.0f;
	float dt = TimeUtils::getDeltaTime();
	float fr = TimeUtils::getFPS();

	particleCenter.x += acceleration * cosf(angle) * dt;
	particleCenter.y -= acceleration * sinf(angle) * dt;
}

void Particle::detectBounds(){

}

void Particle::drawOutline(){

}

void Particle::drawParticle(){
	moveParticle();
	detectBounds();
	drawOutline();
	drawParticle();
}