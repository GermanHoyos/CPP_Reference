#include <iostream>
#include <raylib.h>
#include <cmath>


using namespace std;

int main() {

	const int screenWidth = 800;
	const int screenHeight = 600;
	const float centerWidth = screenWidth / 2;
	const float centerHeight = screenHeight / 2;

	int grid = 365;
	Color dg = Color{ 225, 255, 255, 255 };
	float increment = 0.1f;
	Vector2 center = {0,0};
	Vector2 size = {4,4};

	InitWindow(screenWidth, screenHeight, "C++, By: Adrian Hoyos");
	SetTargetFPS(60);

	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(BLACK);
		
		increment += 0.08f; //affects speed of wave
		int colorOffset = 0;
		for (float y = -grid; y < grid; y += 12)
		{
			for (float x = - grid; x < grid; x += 8)
			{
				float dist = sqrt(x*x + y*y);
				float z = cos(dist / 15 - increment) * 16; //*2 affects depth of wave
				center = {grid + (float)x + (centerWidth - grid ), grid + (float)y - z + (centerHeight - grid)};
				dg.g = -(sin(increment) + colorOffset + dist);
				DrawRectangleV(center,size,dg);
				colorOffset += .1f;
			}
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}