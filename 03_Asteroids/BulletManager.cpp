#include "BulletManager.h"
#include "TimeManager.h"

int Bullet::id = 0;

//Explicitly declared constructor
Bullet::Bullet(float posX, float posY, float r, float angleInput) : x(posX), y(posY), radius(r), angle(angleInput), bulletCenter({ x, y }) {}

void Bullet::moveBullet() {
	//bulletCenter.x++;
	float acceleration = 200.0f;
	dt = TimeUtils::getDeltaTime();
	fr = TimeUtils::getFPS();

	bulletCenter.x += acceleration * cosf(angle) * dt;
	bulletCenter.y -= acceleration * sinf(angle) * dt;

}

void Bullet::drawOutline() {
	DrawCircleV(bulletCenter, radius, WHITE);
}

void Bullet::drawBullet() {
	moveBullet();
	drawOutline();
}
