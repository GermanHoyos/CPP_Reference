#include <iostream>
#include <raylib.h>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>
#include "TimeManager.h"
#include "PlayerManager.h"

void PlayerShip::getGameTimingValues() {
	dt = TimeUtils::getDeltaTime();
	fr = TimeUtils::getFPS();
}

void PlayerShip::drawOutLine() {
	//DrawCircleLines((int)shipCenter.x, (int)shipCenter.y, radius, WHITE);
}

void PlayerShip::drawAngle() {
	Vector2 angleVector = {
	shipCenter.x + radius * cosf(angle),
	shipCenter.y - radius * sinf(angle)
	};
	//DrawLineV(shipCenter, angleVector, GREEN);

	//player shape
	vertex_a = {
		shipCenter.x + radius * cosf(angle),
		shipCenter.y - radius * sinf(angle)
	};
	Vector2 vertex_b = {
		shipCenter.x + radius * cosf(angle + PI * 2 / 3),
		shipCenter.y - radius * sinf(angle + PI * 2 / 3),
	};
	Vector2 vertex_c = {
		shipCenter.x + radius * cosf(angle + PI * 4 / 3),
		shipCenter.y - radius * sinf(angle + PI * 4 / 3),
	};
	Vector2 vertex_d = {
		shipCenter.x + (radius - 25) * cosf(angle),
		shipCenter.y - (radius - 25) * sinf(angle)
	};

	DrawLineV(vertex_a, vertex_b, WHITE);
	DrawLineV(vertex_a, vertex_c, WHITE);
	DrawLineV(vertex_c, vertex_d, WHITE);
	DrawLineV(vertex_b, vertex_d, WHITE);
}

void PlayerShip::moveShip() {
	if (IsKeyDown(265)) {
		newVector.x += acceleration * cosf(angle) * dt;
		newVector.y -= acceleration * sinf(angle) * dt;
		//DrawPixel(
		//	//allows for the visualization of the vector that the object is accelerating towards
		//	shipCenter.x + newVector.x + ((radius) * cosf(angle)),
		//	shipCenter.y + newVector.y - ((radius) * sinf(angle)),
		//RED);
	}
	else {
		newVector.x -= friction * newVector.x * dt;
		newVector.y -= friction * newVector.y * dt;
		//DrawPixel(
		//	//allows for the visualization of the vector that the object is accelerating towards
		//	shipCenter.x + newVector.x + ((radius) * cosf(angle)),
		//	shipCenter.y + newVector.y - ((radius) * sinf(angle)),
		//RED);
	}

	if (IsKeyDown(262)) { //right
		rotation = (dt * 130.00f);
		angle -= rotation * dt;
	}

	if (IsKeyDown(263)) { //left
		rotation = -(dt * 130.00f);
		angle -= rotation * dt;
	}

	if (IsKeyDown(32)) {
		//Bullet bullet(vertex_a);
	}

	//this moved player based on new vector
	shipCenter.x += newVector.x;
	shipCenter.y += newVector.y;
	
	//check if player has left bounds
	if (shipCenter.x < 210){
		shipCenter.x = 800;
	};
	if (shipCenter.y < 0) {
		shipCenter.y = 600;
	};
	if (shipCenter.x > 800){
		shipCenter.x = 210;
	};
	if (shipCenter.y > 600){
		shipCenter.y = 0;
	};



}

void PlayerShip::drawShip() {
	getGameTimingValues();
	drawOutLine();
	drawAngle();
	moveShip();
}
