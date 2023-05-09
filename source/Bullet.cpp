#include "Bullet.h"

Bullet::Bullet(SDL_Renderer* renderer, Vector2 pos, float angle)
	: GameObject(renderer, 10, 10, Vector2(32, 30)) {

	Vector2 bulletSpawn = pos + (Vector2(cos(angle), sin(angle)) * 20);
	position = bulletSpawn;
	rotation = 0.0f;
	scale = Vector2(1, 1);

	velocity = (bulletSpawn - pos) * 30;
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 0.3f;
	angularDrag = 0.0f;

	accelerationFactor = 0.0f;
	angularAccelerationFactor = 0.0f;

}

void Bullet::Update(float dt) {

	timeAlive += dt;

	if (timeAlive > timeToLive) {
		toDestroy = true;

	}

	GameObject::Update(dt);

}