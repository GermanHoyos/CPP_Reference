#include "raylib_and_all_headers_wrapper.h"
#include "NpcManager.h"
#include "TextureManager.h"


//Vector2 screen = { 800, 600 };
//Vector2 direction;
//float friction = 2.00f;
//float magnitude;
//float magnitudeReducer;
//float finalMagnitude;

Npc::Npc(float posX, float posY, float velX, float velY, float r, Texture2D ships) 
	:  position({ posX, posY}), velocity({velX, velY}), radius(r), ships(ships) {

}

void Npc::moveNpc(){

	//move Npc to the left
	//velocity.x--;

	float acceleration = 100.0f;
	float dt = TimeUtils::getDeltaTime();

	// Calculate the angle in radians based on the rotation (in degrees)
	float angle = (float)rotation * DEG2RAD; //this starts off at 0 degrees

	// Calculate the direction vector of the ray
	direction = { cosf(angle), -sinf(angle) };

	// Update the velocity vector based on the direction and acceleration
	velocity.x = direction.x * acceleration * dt;

	// Check if Npc has left bounds
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

void Npc::detectBounds(){
	if (radialTrigger) {
		DrawCircleLines(position.x, position.y, radius * 1, RED);
	}
	else {
		DrawCircleLines(position.x, position.y, radius * 1, GREEN);
	}                      
}

void Npc::renderNpc(){
	
	// Focus only on portion of sprite desired
	int textureW = ships.width / 2; //split the image into 2 equal parts
	int textureH = ships.height;

	// Source rectangle (part of the texture to use for drawing)
	Rectangle sourceRec = { 16.0f, 0.0f, (float)textureW, (float)textureH };

	// Outline square where sprite will be loaded
	// Destination rectangle (screen rectangle where drawing part of texture)
	Rectangle destRec = { position.x, position.y, textureW * 5.0f, textureH * 5.0f };

	// Origin of the texture (rotation/scale point), it's relative to destination rectangle size
	Vector2 origin = { (float)textureW * 5.0f / 2, (float)textureH * 5.0f / 2 };

	// Draw Texture
	// In regard to rotation, the drawing context squares center matches the center of the underlay
	// circle, however rotating the circle does not move that center. Thus you must match the rotation
	// of the underlay circle by passing a rotation float to the DrawTexturePro square itself
	DrawTexturePro(ships, sourceRec, destRec, origin, 0, WHITE);
}

void Npc::drawNpc(){
	moveNpc();
	detectBounds();
	renderNpc();
}
