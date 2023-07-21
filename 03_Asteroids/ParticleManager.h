#pragma once
#include <vector>
#include <raylib.h>

class Particle {
public:
	static int id;
	int myId;
	float x;
	float y;
	float radius;
	float angle;

	Vector2 particleCenter;

	Particle(float posX, float posY, float r, float angle);

	void moveParticle();
	void detectBounds();
	void drawOutline();
	void drawParticle();

};

class ParticleManager {
public:
	static std::vector<Particle> asteroidList;
};