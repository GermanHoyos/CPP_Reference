#include <iostream>
#include <raylib.h>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main() {

	const int screenWidth = 800;
	const int screenHeight = 600;
	const float centerWidth = screenWidth / 2;
	const float centerHeight = screenHeight / 2;
	int grid = 365;
	float increment = 0.1f;
	Vector2 box = { 0, 0 };
	Vector2 size = { 4, 4 };

	InitWindow(screenWidth, screenHeight, "C++, By: Adrian Hoyos");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		increment += 0.08f; // affects speed of wave

		for (float y = -grid; y < grid; y += 12) {
			for (float x = -grid; x < grid; x += 8) {
				float dist = sqrt(x * x + y * y); // distance from center
				float z = cos(dist / 15 - increment) * 16; // *2 affects depth of wave

				Color dg = Color{ 191, 0, 255, 255 }; // Base color

				dg.g = z;

				if (z > 13.0f ) {
					// Calculate color within specific height range
					dg.r = 255;
					dg.g = 0;
					dg.b = 0; 
				}

				box = { grid + x + (centerWidth - grid), grid + y - z + (centerHeight - grid) };
				DrawRectangleV(box, size, dg);
			}
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
