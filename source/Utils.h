#pragma once
#include "Vector2.h"
#include <stdlib.h>

#define GAME_WIDTH 500
#define GAME_HEIGHT 500
#define M_PI 3.12159265358979323846

inline float CalculateRadius(int width, int height) {

	float a = ((float)GAME_WIDTH / 2.f);
	a *= a; //power of two

	float b = ((float)GAME_HEIGHT / 2.f);
	b *= b;

	float h = sqrt(a + b); //this is the radius

	return h;

}

inline Vector2 CalculatePositionInRadius(float r) {

	Vector2 perimeterPosition;

	float angle = rand() % 360;
	angle *= M_PI / 180.0f; //DEG TO RAD

	perimeterPosition.x = cos(angle) * r;
	perimeterPosition.y = sin(angle) * r;

	return perimeterPosition;

}

inline Vector2 ClamPositionToRectangle(Vector2 pos, float halfWidth, float halfHeight) {

	if (pos.y < -halfHeight) // TOP clamp
		pos.y = -halfHeight;

	if (pos.y > halfHeight) //BOTTOM clamp
		pos.y = halfHeight;

	if (pos.x < -halfWidth) //LEFT clamp
		pos.x = -halfWidth;

	if (pos.x > halfWidth) //RIGHT clamp
		pos.x = halfWidth;

	return pos;

}