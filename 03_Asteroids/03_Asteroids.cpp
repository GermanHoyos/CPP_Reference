#include <iostream>
#include <raylib.h>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include "PlayerManager.h"
#include "BulletManager.h"
#include "AsteroidManager.h"

#define M_PI 3.14

using namespace std;
//For simplicity I will be referencing the 3 core functions of PICO-8 and match
//said functionality to this raylib implementation of asteroids

/*
The 3 core functions of PICO-8 = 
	1) function _INIT()
	2) function _UPDATE  (30x a sec)
	3) function _DRAW	 (Post Update, 30x a sec)
*/

//Global Scope
//cannot not instantiate inside the scope of the main() function
vector<Bullet> BulletManager::bulletList;
vector<Asteroid> AsteroidManager::asteroidList;

void checkForAsteroidCollisions() {
	for (Asteroid& asteroid1 : AsteroidManager::asteroidList) {
		Vector2 mainAsteroid = { asteroid1.position.x, asteroid1.position.y };
		int mainRadius = asteroid1.radius;
		int mainId = asteroid1.myId; // Use asteroid1.myId instead of asteroid1.id
		bool alreadyNotified = false;

		for (Asteroid& asteroid2 : AsteroidManager::asteroidList) {
			if (mainId != asteroid2.myId) { // Use asteroid2.myId instead of asteroid2.id
				Vector2 otherAsteroid = { asteroid2.position.x, asteroid2.position.y };
				int otherRadius = asteroid2.radius;

				double distanceBetweenAsteroids = sqrt(
					pow((mainAsteroid.x - otherAsteroid.x), 2) +
					pow((mainAsteroid.y - otherAsteroid.y), 2)
				);

				if (distanceBetweenAsteroids <= mainRadius + otherRadius) {
					if (!alreadyNotified) {
						DrawText("COLLIDED", mainAsteroid.x, mainAsteroid.y, 20, GREEN);
						alreadyNotified = true;

						//// ::HANDLE COLLISIONS NOW THAT COLLISIONS ARE DETECTED::
						//// 1) subtract vectors
						//float subtractedVectorX = mainAsteroid.x - otherAsteroid.x;
						//float subtractedVectorY = mainAsteroid.y - otherAsteroid.y;
						//Vector2 finalSubtractedVector = { subtractedVectorX, subtractedVectorY };

						//// 2) get length (hypotnuse) of traingle
						//float length = sqrt(subtractedVectorX * subtractedVectorX + subtractedVectorY * subtractedVectorY);

						//// 3) "normalize", or reduce the length to a unit value of 1
						//float normalizedVectorX = subtractedVectorX / length;
						//float normalizedVectorY = subtractedVectorY / length;

						//// 4) use the "dot product" (Dot Product = A.x * B.x + A.y * B.y) to compute change in velocity
						//	//asteroid 1 (or main asteroid)
						//float mainAsteroidDotP = asteroid1.velocity.x * normalizedVectorX + asteroid1.velocity.y * normalizedVectorY;
						//asteroid1.velocity.x = asteroid1.velocity.x * mainAsteroidDotP * normalizedVectorX;
						//asteroid1.velocity.y = asteroid1.velocity.y * mainAsteroidDotP * normalizedVectorY;

						//float othrAsteroidDotP = asteroid2.velocity.x * normalizedVectorX + asteroid2.velocity.y * normalizedVectorY;
						//asteroid2.velocity.x = asteroid2.velocity.x * othrAsteroidDotP * normalizedVectorX;
						//asteroid2.velocity.y = asteroid2.velocity.y * othrAsteroidDotP * normalizedVectorY;

			
						//// ::HANDLE COLLISIONS NOW THAT COLLISIONS ARE DETECTED::
						// 1) subtract vectors
						Vector2 collisionNormal = { mainAsteroid.x - otherAsteroid.x, mainAsteroid.y - otherAsteroid.y };

						// 2) get length (hypotnuse) of traingle
						float length = sqrt(collisionNormal.x * collisionNormal.x + collisionNormal.y * collisionNormal.y);

						// 3) "normalize" the collisionNormal / reduce the length to a unit value of 1
						collisionNormal.x /= length;
						collisionNormal.y /= length;

						// 4) use the "dot product" (Dot Product = A.x * B.x + A.y * B.y) to compute change in velocity
						float mainAsteroidDotP = asteroid1.velocity.x * collisionNormal.x + asteroid1.velocity.y * collisionNormal.y;
						float otherAsteroidDotP = asteroid2.velocity.x * collisionNormal.x + asteroid2.velocity.y * collisionNormal.y;

						// Use the law of conservation of momentum to update velocities
						// asteroid 1
						asteroid1.velocity.x = asteroid1.velocity.x - 2 * mainAsteroidDotP * collisionNormal.x;
						asteroid1.velocity.y = asteroid1.velocity.y - 2 * mainAsteroidDotP * collisionNormal.y;
						// asteroid 2
						asteroid2.velocity.x = asteroid2.velocity.x - 2 * otherAsteroidDotP * collisionNormal.x;
						asteroid2.velocity.y = asteroid2.velocity.y - 2 * otherAsteroidDotP * collisionNormal.y;

						// Add a small separation distance to the position of both asteroids
						// without this, the asteroids seem to stick together
						float separationDistance = 2.0f;
						asteroid1.position.x += separationDistance * collisionNormal.x;
						asteroid1.position.y += separationDistance * collisionNormal.y;

						asteroid2.position.x -= separationDistance * collisionNormal.x;
						asteroid2.position.y -= separationDistance * collisionNormal.y;



					}
				}
			}
		}
	}
}

/*

						// Reflect the velocity of asteroid1 along the collision direction
						// This will cause the asteroid to change direction after collision
						float dotProduct = asteroid1.velocity.x * normalVectorX + asteroid1.velocity.y * normalVectorY;
						asteroid1.velocity.x = asteroid1.velocity.x - 2.0f * dotProduct * normalVectorX;
						asteroid1.velocity.y = asteroid1.velocity.y - 2.0f * dotProduct * normalVectorY;

						// Reflect the velocity of asteroid2 along the collision direction
						dotProduct = asteroid2.velocity.x * normalVectorX + asteroid2.velocity.y * normalVectorY;
						asteroid2.velocity.x = asteroid2.velocity.x - 2.0f * dotProduct * normalVectorX;
						asteroid2.velocity.y = asteroid2.velocity.y - 2.0f * dotProduct * normalVectorY;
					}

*/


//handle collision
//float normalVectorX = mainAsteroid.x - otherAsteroid.x;
//float normalVectorY = mainAsteroid.y - otherAsteroid.y;

////calc length of above normal vector
//float length = sqrt(normalVectorX * normalVectorX + normalVectorY * normalVectorY);

////normalize the normal vector
//normalVectorX /= length;
//normalVectorY /= length;

//calc velocity may not be needed since velocity will not change
//relative_velocity = (circle2.vx - circle1.vx) * nx + (circle2.vy - circle1.vy) * ny

//update vectors for both circles
//asteroid1.asteroidCenter.x += 1 * normalVectorX;
//asteroid1.asteroidCenter.y += 1 * normalVectorY;
//Vector2 newAsteroidDirection1 = {normalVectorX,normalVectorY}; 


//asteroid2.asteroidCenter.x -= 1 * normalVectorX;
//asteroid2.asteroidCenter.y -= 1 * normalVectorY;
//Vector2 newAsteroidDirection2 = {normalVectorX,normalVectorY};

//somehow update angles?


int main() { //PICO 8 FUNCTION _INIT()

	//Window initialization
	InitWindow(800, 600, "Asteroids in C++ [Raylib]");
	SetTargetFPS(60);

	//Timing variables
	int gameTotalSeconds = GetTime();
	int seconds = 0;
	int minutes = 0;
	float deltaTime;

	//Input Variables
	int pressedKey = 0;
	string pressedKey_str;

	//Game Objects
	PlayerShip playerShip;
	bool buildAnotherAsteroid = false;
	int bullet_id;
	int asteroid_id;

	//Collision vectors
	Vector2 bullet_center_check;
	Vector2 asteroid_center_check;

	//If window isnt closed, continue to run game
	while (!WindowShouldClose()) { //PICO 8 FUNCTION _UPDATE()
				
		BeginDrawing(); //PICO 8 _DRAW()
		ClearBackground(BLACK);

		//Timing mechanics
		deltaTime = GetFrameTime();
		int currentTime = GetTime();
		if (gameTotalSeconds != currentTime) {
			seconds++;
			if (seconds == 60) {
				seconds = 0;
				minutes++;
			}
			gameTotalSeconds = currentTime;
		}
		string seconds_str = "Seconds: " + to_string(seconds);
		string minutes_str = "Minutes: " + to_string(minutes);
		string deltaTime_str = "Delta Time: " + to_string(deltaTime);

		//General input mechanics
		for (int key = 0; key < 300; key++) {
			if(IsKeyPressed(key)){
				pressedKey = key;
				pressedKey_str = "Key Pressed: " + to_string(pressedKey);
			}
		}

		//If the "space" key is pressed insert a bullet into the bullet list
		if (pressedKey == 32) {
			float x = playerShip.shipCenter.x;
			float y = playerShip.shipCenter.y;
			float angle = playerShip.angle;
			float rad = 2.0f;

			BulletManager::bulletList.emplace_back(x, y, rad, angle);
			pressedKey = 0;
		}

		//create an asteroid every X seconds only once
		if (seconds % 2 == 0)
		{
			//InitWindow(800, 600, "Asteroids in C++ [Raylib]");
			//width  800 //red line 210
			//height 600

			//stops the function from creating more than 1 asteroid every Nth second
			if (buildAnotherAsteroid == true)
			{
				//MERSENNE TWISTER pseudo-random number generator with a seed of "19937"
				//https://en.wikipedia.org/wiki/Mersenne_Twister
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<int> global_func_dist(1, 4);

				int wall_chosen = global_func_dist(gen);
				//int wall_chosen = 4; //for TS individual walls

				int x;
				int y;
				float asteroid_radius = 35.0f;
				float direction_of_travel;

				//top 210degrees to 330degrees
				if (wall_chosen == 1) {
					uniform_int_distribution<int> dist(220, 800);
					uniform_real_distribution<float> rand_x(-1, 1); //generates a random degree to be passed as argument
			
					x = dist(gen);
					y = 10;
										
					AsteroidManager::asteroidList.emplace_back(x, y,rand_x(gen),1,20);
				}

				//left 60degrees to 315degrees
				if (wall_chosen == 2) {
					uniform_int_distribution<int> dist(10, 600);
					uniform_real_distribution<float> rand_y(-1, 1);

					x = 240;
					y = dist(gen);
					
					AsteroidManager::asteroidList.emplace_back(x, y, 1, rand_y(gen), 20);

				}

				//right 120degrees to 240degrees
				if (wall_chosen == 3) {
					uniform_int_distribution<int> dist(10, 600);
					uniform_real_distribution<float> rand_y(-1, 1);

					x = 790;
					y = dist(gen);
					
					AsteroidManager::asteroidList.emplace_back(x, y,-1,rand_y(gen),20);
				}

				//top 210degrees to 330degrees
				if (wall_chosen == 4) {
					uniform_int_distribution<int> dist(220, 800);
					uniform_real_distribution<float> rand_x(-1, 1); //generates a random degree to be passed as argument

					x = dist(gen);
					y = 580;

					AsteroidManager::asteroidList.emplace_back(x, y, rand_x(gen), -1, 20);
				}

				DrawText(to_string(wall_chosen).c_str(), 2, 80, 20, GREEN);
				//DrawText(to_string(x).c_str(), 2, 100, 20, GREEN);
				
				buildAnotherAsteroid = false;
			}
		} else {
			buildAnotherAsteroid = true;
		}

		//Console
		DrawLine(210,0,210,600,RED);
		DrawFPS(2, 2);
		DrawText(seconds_str.c_str(),2, 20, 20,GREEN);
		DrawText(minutes_str.c_str(), 2, 40, 20, GREEN);
		DrawText(deltaTime_str.c_str(), 2, 60, 20, GREEN);
		DrawText(pressedKey_str.c_str(), 2, 80, 20, GREEN);

		//Final draw calls
		playerShip.drawShip();
		
		//If the bullet list index's has any bullets at all inside of it, then draw said
		//bullet with the bullets "void DrawBullet()" function
		for (Bullet& bullet : BulletManager::bulletList) { //* see explanation below
			bullet.drawBullet();
			//bullet_center_check = bullet.bulletCenter;
		}
		//Another way of showing particular bullets for troubleshooting
		//if (!BulletManager::bulletList.empty()){
		//	BulletManager::bulletList.at(0).drawBullet();
		//}
		for (Asteroid& asteroid : AsteroidManager::asteroidList) { //* see explanation below
			asteroid.drawAsteroid();
			//asteroid_center_check = asteroid.asteroidCenter;
		}
		
		//currently this is an in efficent way to do this
		//in the future implement "Broad-Phase collision detection"
		//and "Narrow-Phase" collision detection
		checkForAsteroidCollisions();


		EndDrawing();
	}

	CloseWindow();

	return 0;
}

/*
   for (Bullet& bullet : BulletManager::bulletList)
   for (variable declaration : range expression)
	   Bullet& bullet: This declares a variable bullet of type Bullet&,
	   which means it is a reference to an object of type Bullet. The 
	   reference is necessary to directly access and modify the elements
	   in the range without making a copy. : (colon): It separates the 
	   variable declaration from the range expression. BulletManager::bulletList: 
	   This is the range expression, which specifies the container or
	   range of elements to iterate over. In this case, it refers to the
	   static member variable bulletList of the BulletManager class.
	::
		The :: in C++ is known as the scope resolution operator. It is 
		used to access members (variables, functions, or nested types) of
		a namespace, class, or structure. It is not technically an operator
		in the same sense as arithmetic or logical operators.
		It is used solely for scoping purposes in C++.
*/