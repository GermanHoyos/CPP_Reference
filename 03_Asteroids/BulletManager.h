#pragma once
#ifndef BULLET_MANAGER_H //ifndef = if not defined
#define BULLET_MANAGER_H
#include <vector>
#include <raylib.h>

class Bullet {
public:
	static int id;
	int myId;
	float x;
	float y;
	float radius;
	float angle;
	bool out_of_bounds = false;
	bool hit_asteroid = false;

	Vector2 bulletCenter;

	Bullet(float posX, float posY, float r, float angle);

	void moveBullet();
	void detectBounds();
	void detectAsteroids();
	void drawOutline();
	void drawBullet();
};

class BulletManager { //* see explanation below
public:
	static std::vector<Bullet> bulletList;
};


/*
 In C++, when a member variable is declared as
 static in a class, it means that the variable
 is shared among all instances of the class rather
 than being specific to each instance. Static
 members belong to the class itself rather than
 individual objects.

Since the bulletList variable in BulletManager
is declared as a static member, it exists independently
of any specific object of the BulletManager class. It
is associated with the class itself rather than with
individual instances.

As a result, you cannot instantiate or initialize
a static member inside a function like main(). The
reason is that the static member needs to be defined
and allocated memory outside of any function to ensure
its global scope and availability to all instances of
the class.
*/


#endif
