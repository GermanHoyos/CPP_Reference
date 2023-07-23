#include "ParticleManager.h"
#include "TimeManager.h"
#include <string>
#include <algorithm>
#include <random>

using namespace std;

int Particle::id = 0;
Vector2 explosionCenter;


//Explicitly declared constructor
Particle::Particle(float posX, float posY, float velX, float velY, float r)
		: position({posX, posY}), velocity({velX, velY}), radius(r), myId(id++) {
		//::additional init logic here::
}

void Particle::moveParticle(){
	//implement angles such that it travels inward from all 4 walls
	float acceleration = 120.0f;
	float dt = TimeUtils::getDeltaTime();

	//example of how angles would be used, but not recomended
	/*particleCenter.x += acceleration * cosf(angle) * dt;
	particleCenter.y -= acceleration * sinf(angle) * dt;*/

	//vectors approach
	position.x += velocity.x * acceleration * dt;
	position.y += velocity.y * acceleration * dt;

	//for (Particle& particle : ParticleManager::particleList) {
	//	if (particle.position.x > explosionCenter.x + 10 || particle.position.x < explosionCenter.x - 10){
	//			//findMe = BulletManager::bulletList.erase(findMe);
	//			ParticleManager::particleList.erase(particle);
	//	}
	//}	

	//for (auto findMe = BulletManager::bulletList.begin(); findMe != BulletManager::bulletList.end(); ) {
	//	if (findMe->out_of_bounds) {
	//		findMe = BulletManager::bulletList.erase(findMe);
	//	}
	//	else {
	//		++findMe;
	//	}
	//}

	float radius = 150.0f;

	for (auto exceededBoundsParticle = ParticleManager::particleList.begin(); exceededBoundsParticle != ParticleManager::particleList.end();) {
		float distanceToExplosion = sqrt(
			pow(explosionCenter.x - exceededBoundsParticle->position.x, 2) +
			pow(explosionCenter.y - exceededBoundsParticle->position.y, 2)
		);

		if (distanceToExplosion > radius) {
			exceededBoundsParticle = ParticleManager::particleList.erase(exceededBoundsParticle);
		}
		else {
			++exceededBoundsParticle;
		}
	}

}

void Particle::detectBounds(){

}

void Particle::drawOutline(){

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> alpha_(100,225);
	uniform_int_distribution<int> red_(1, 225);
	uniform_int_distribution<int> green_(1, 225);
	uniform_int_distribution<int> blue_(125, 225);

	unsigned char final_alpha = static_cast<unsigned char>(alpha_(gen));
	unsigned char final_red = static_cast<unsigned char>(red_(gen));
	unsigned char final_green = static_cast<unsigned char>(green_(gen));
	unsigned char final_blue = static_cast<unsigned char>(blue_(gen));

	DrawCircleV(position, radius, { final_red,final_green,final_blue,final_alpha });
}

void Particle::drawParticle(){
	moveParticle();
	detectBounds();
	drawOutline();
}

//standalone
//particle functions
//call this when an asteroid is hit by a bullet
//have the call of this function be made from the instantiated bullet
void Particle::genParticle(float x, float y) {
	//if you generate random velocity components for both x and why
	//enough times with will simulate 360degree explosions
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> rand_xy(-1, 1);

	//keep track of explosions origin point so that you can
	explosionCenter = {x,y};

	//velocity = speed and direction in vector maths
	ParticleManager::particleList.emplace_back(x, y, rand_xy(gen), rand_xy(gen), 2);

}