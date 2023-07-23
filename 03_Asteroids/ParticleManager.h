#pragma once
#include <vector>
#include <raylib.h>

class Particle {
public:
	static int id;
	int myId;
	float radius;
	Vector2 position; //current particle center
	Vector2 velocity; //represents both speed and direction, but updating this you can simulate movement

	Particle(float posX, float posY, float velX, float velY, float r);

	void moveParticle();
	void detectBounds();
	void drawOutline();
	void drawParticle();

	//call to instantiate
	void static genParticle(float x, float y);

};

class ParticleManager {
public:
	static std::vector<Particle> particleList;
};