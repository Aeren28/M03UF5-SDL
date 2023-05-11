#include "Bullet.h"

Bullet::Bullet(SDL_Renderer* renderer, Vector2 pos, float angle, float velocityFactor)
	: GameObject(renderer, 10, 10, Vector2(32, 30)) {

	Vector2 bulletSpawn = pos + (Vector2(cos(angle), sin(angle)) * 20);
	position = bulletSpawn;

	velocity = Vector2(cos(angle), sin(angle)) * velocityFactor;
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 0.3f;
	angularDrag = 0.0f;

	accelerationFactor = 0.0f;
	angularAccelerationFactor = 0.0f;

	lifeTime = 0.8;

}

void Bullet::Update(float dt) {

	GameObject::Update(dt);
	UpdateLifeTime(dt);

}

void Bullet::UpdateLifeTime(float dt){

	lifeTime -= dt;

	if (lifeTime <= 0.0f)
		Destroy();

}