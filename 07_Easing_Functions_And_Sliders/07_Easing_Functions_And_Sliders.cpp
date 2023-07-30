using namespace std;
#include "raylib_and_all_headers_wrapper.h"
#include "TimeManager.h"
#include "InputManager.h"

int main()
{
	Vector2 screen = { 800, 600 };
	InitWindow(screen.x, screen.y, "C++ Raylib");
	Vector2 circleOrigin = { screen.x / 2, screen.y / 2 };
	float radius = 200;
	float angleVar = 0.0f;
	float angle = angleVar / 180.0f * PI; // scalar value in radians	

	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground({ 29, 43, 83, 225 });
		TimeUtils::displaySystemTime();
		InputUtils::printKey();

		// Change Angle:
		angleVar++; // clockwise
		angle = angleVar / 180.0f * PI;
		if (angleVar >= 360) {angleVar = 0;}

		// Circle:
		DrawCircleV(circleOrigin, radius, BLACK);
		// Cos:
		DrawLineV(
			{circleOrigin.x,circleOrigin.y}, //start
			{circleOrigin.x + radius * cosf(angle), circleOrigin.y}, //end
			RED //color
		);
		// Sin:
		DrawLineV(
			{circleOrigin.x + radius * cosf(angle),circleOrigin.y}, //start
			{circleOrigin.x + radius * cosf(angle),circleOrigin.y + radius * sinf(angle)}, //end
			GREEN //color
		);
		// Angle:
		DrawLineV(
			{circleOrigin.x,circleOrigin.y}, //start
			{circleOrigin.x + radius * cosf(angle),circleOrigin.y + radius * sinf(angle)}, //end
			WHITE
		);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
