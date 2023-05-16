#include "Asteroid.h"

Asteroid::Asteroid(SDL_Renderer* rend)
	: GameObject(rend, 0, 0, Vector2()) {
	
	//CALCULATE RADIUS
	float spawnradius = CalculateRadius(GAME_WIDTH, GAME_HEIGHT);

	//CALCULATE POSITION IN SPHERE PERIMETER WITH A GIVEN RADIUS (h)
	Vector2 perimeterPosition = CalculatePositionInRadius(spawnradius);

	//CLAMP TO  RECTANGLE WITH WIDTH AND HEIGHT
	float halfHeight = (float)GAME_HEIGHT / 2.f + (float)radius;
	float halfWidth = (float)GAME_WIDTH / 2.f + (float)radius;

	perimeterPosition = ClamPositionToRectangle(perimeterPosition, halfWidth, halfHeight);
	
	//TRANSFORM
	position = perimeterPosition;
	position = position + Vector2(halfWidth, halfHeight);
	rotation = rand() % 360;
	scale = Vector2(1.0f, 1.0f);

	//PHYSICS
	acceleration = Vector2(0.0f, 0.0f);
	angularAcceleration = 0.0f;
	linearDrag = 0.0f;
	angularDrag = 0.0f;

	velocity = Vector2();
	angularVelocity = 0.0f;
}