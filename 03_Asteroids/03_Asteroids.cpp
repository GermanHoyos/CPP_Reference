#include <iostream>
#include <raylib.h>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include "PlayerManager.h"
#include "BulletManager.h"
#include "AsteroidManager.h"

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

				//int wall_chosen = rand() % 4 + 1; // 1 through 4 randomly gen
				int wall_chosen = global_func_dist(gen);
				int x;
				int y;
				float asteroid_radius = 35.0f;
				float direction_of_travel;

				//top 210degrees to 330degrees
				if (wall_chosen == 1) {
					uniform_int_distribution<int> dist(220, 800);
					uniform_real_distribution<float> rand_degree(210.0f, 330.0f);
			
					x = dist(gen);
					y = 10;
					direction_of_travel =  rand_degree(gen) / 180.0f * PI;
					AsteroidManager::asteroidList.emplace_back(x, y, asteroid_radius, direction_of_travel);
				}

				//left 60degrees to 315degrees
				if (wall_chosen == 2) {
					uniform_int_distribution<int> dist(10, 600);
					uniform_real_distribution<float> rand_degree(60.0f, 315.0f);

					x = 240;
					y = dist(gen);
					direction_of_travel = rand_degree(gen) / 180.0f * PI;
					AsteroidManager::asteroidList.emplace_back(x, y, asteroid_radius, direction_of_travel);
				}

				//right 120degrees to 240degrees
				if (wall_chosen == 3) {
					uniform_int_distribution<int> dist(10, 600);
					uniform_real_distribution<float> rand_degree(120.0f, 240.0f);

					x = 790;
					y = dist(gen);
					direction_of_travel = rand_degree(gen) / 180.0f * PI;
					AsteroidManager::asteroidList.emplace_back(x, y, asteroid_radius, direction_of_travel);
				}

				//bottom 30degrees to 150degrees
				if (wall_chosen == 4) {
					uniform_int_distribution<int> dist(220, 800);
					uniform_real_distribution<float> rand_degree(30.0f, 150.0f);

					x = dist(gen);
					y = 590;
					direction_of_travel = rand_degree(gen) / 180.0f * PI;
					AsteroidManager::asteroidList.emplace_back(x, y, asteroid_radius, direction_of_travel);
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
			bullet_center_check = bullet.bulletCenter;
		}
		//Another way of showing particular bullets for troubleshooting
		//if (!BulletManager::bulletList.empty()){
		//	BulletManager::bulletList.at(0).drawBullet();
		//}
		for (Asteroid& asteroid : AsteroidManager::asteroidList) { //* see explanation below
			asteroid.drawAsteroid();
			asteroid_center_check = asteroid.asteroidCenter;
		}


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