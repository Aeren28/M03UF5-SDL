#include "DeathParticles.h"

DeathParticles::DeathParticles(SDL_Renderer* rend, Vector2 pos)
	: GameObject(rend, 0, 0, Vector2()) {

	// PHYSICS
	acceleration = Vector2(0.0f, 0.0f);
	angularAcceleration = 30 + rand() % 80;
	linearDrag = 0.0f;
	angularDrag = 0.0f;

	velocity = Vector2();
	angularVelocity = 0.0f;


	width = 3;
	height = 36;
	padding = Vector2(79.0f, 69.0f);

	// TRANSFORM
	Vector2 randomOffset = Vector2(10 - (rand() % 21), 10 - (rand() % 21));
	position = pos + randomOffset;
	rotation = rand() % 360;
	scale = Vector2(1.0f, 1.0f);

}