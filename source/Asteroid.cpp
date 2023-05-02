#include "Asteroid.h"

Asteroid::Asteroid(SDL_Renderer* rend)
	: GameObject(rend, 40, 40, Vector2(40, 0)) {

	//CALCULATE RADIUS
	int r = width > height ? width / 2 : height / 2;

	float a = ((float)GAME_WIDTH / 2.f + (float)r);
	a *= a; //power of two

	float b = ((float)GAME_HEIGHT / 2.f + (float)r);
	b *= b;

	float h = sqrt(a + b);

	//CALCULATE POSITION IN SPHERE PERIMETER WITH A GIVEN RADIUS	
	Vector2 perimeterPosition;
	float angle = rand() % 360;
	angle *= M_PI / 180.0f; //DEG TO RAD
	perimeterPosition.x = cos(angle) * h;
	perimeterPosition.y = sin(angle) * h;

	//CLAMP TO  RECTANGLE WITH WIDTH AND HEIGHT
	float halfHeight = (float)GAME_HEIGHT / 2.f + (float)r;
	float halfWidth = (float)GAME_WIDTH / 2.f + (float)r;

	if (perimeterPosition.y < -halfHeight) // TOP clamp
		perimeterPosition.y = -halfHeight;

	if (perimeterPosition.y > halfHeight) //BOTTOM clamp
		perimeterPosition.y = halfHeight;

	if (perimeterPosition.x < -halfWidth) //LEFT clamp
		perimeterPosition.x = -halfWidth;
	
	if (perimeterPosition.x > halfWidth) //RIGHT clamp
		perimeterPosition.x = halfWidth;

	position = perimeterPosition;
	position = position + Vector2(halfWidth, halfHeight);

	velocity = Vector2(100, 100);
}