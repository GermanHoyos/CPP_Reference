#include "raylib_and_all_headers_wrapper.h"
#include "PlayerManager.h"
#include "TextureManager.h"


// Screen dimensions
Vector2 screen = { 800, 600 };
Vector2 direction;
float friction = 2.00f;
float magnitude;
float magnitudeReducer;
float finalMagnitude;

Player::Player(float posX, float posY, float velX, float velY, float r, Texture2D ships)
	: position({ posX, posY }), velocity({ velX, velY }), radius(r), ships(ships) {
	// Aditional implementation code here
}

void Player::movePlayer() {

	float acceleration = 10.0f;
	float dt = TimeUtils::getDeltaTime();

	if (IsKeyDown(KEY_RIGHT)) {
		rotation--;
	}

	if (IsKeyDown(KEY_LEFT)) {
		rotation++;
	}

	if (IsKeyDown(KEY_UP)) {

		// Calculate the angle in radians based on the rotation (in degrees)
		float angle = (float)rotation * DEG2RAD;

		// Calculate the direction vector of the ray
		direction = { cosf(angle), -sinf(angle) };

		// Update the velocity vector based on the direction and acceleration
		velocity.x += direction.x * acceleration * dt;
		velocity.y += direction.y * acceleration * dt;
	
	} else {
		
		// Get current speed (magnitude of velocity vector)
		magnitude = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y); 
		
		// This will grab current magnitude and reduce the magnitudeReducer to 0 over time
		magnitudeReducer = magnitude - friction * dt;

		// Compare magnitude to 0 and if > true derive final magnitude
		if (magnitude > 0) {
			finalMagnitude = magnitudeReducer / magnitude;
		}
		
		// Apply final magnitude to x,y velocities
		velocity.x *= finalMagnitude;
		velocity.y *= finalMagnitude;
	}

	// Check if player has left bounds
	if (position.x < 0) {
		position.x = 800;
	};
	if (position.y < 0) {
		position.y = 600;
	};
	if (position.x > 800) {
		position.x = 0;
	};
	if (position.y > 600) {
		position.y = 0;
	};


	// Update the position of the ship based on the velocity
	position.x += velocity.x;
	position.y += velocity.y;
}


void Player::detectBounds() {

}

void Player::renderPlayer() {

	// Draw rotated circle
	DrawCircleSector(position, radius, 0, rotation, 30, {0,0,0,0});

	// Focus only on portion of sprite desired
	int textureW = ships.width / 2; //split the image into 2 equal parts
	int textureH = ships.height;

	// Source rectangle (part of the texture to use for drawing)
	Rectangle sourceRec = { 0.0f, 0.0f, (float)textureW, (float)textureH };

	// Outline square where sprite will be loaded
	// Destination rectangle (screen rectangle where drawing part of texture)
	Rectangle destRec = { position.x, position.y, textureW * 5.0f, textureH * 5.0f };

	// Origin of the texture (rotation/scale point), it's relative to destination rectangle size
	Vector2 origin = { (float)textureW * 5.0f / 2, (float)textureH * 5.0f / 2 };

	// Draw Texture
	// In regard to rotation, the drawing context squares center matches the center of the underlay
	// circle, however rotating the circle does not move that center. Thus you must match the rotation
	// of the underlay circle by passing a rotation float to the DrawTexturePro square itself
	DrawTexturePro(ships, sourceRec, destRec, origin, -rotation, WHITE);
	DrawCircleV({position.x + radius * cosf(rotation / 180.0f * PI), position.y - radius * sinf(rotation / 180.0f * PI)},	5, GREEN);

}

void Player::drawPlayer() {
	movePlayer();
	detectBounds();
	renderPlayer();
}

