#pragma once
using namespace std;
#include "raylib_and_all_headers_wrapper.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "PlayerManager.h"
#include "TextureManager.h"

Texture2D LdTextures::returnPlayer() {
	Texture2D ships = LoadTexture("ships.png");
	return ships;
};

//Texture2D LdTextures::returnNpc() {
//	return ;
//};