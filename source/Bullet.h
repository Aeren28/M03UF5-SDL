#pragma once

#include "GameObject.h"

class Bullet : public GameObject {

public:

	Bullet(SDL_Renderer* renderer, Vector2 pos, float angle, float velocityFactor);

protected:
	float lifeTime;

	void Update(float dt) override;
	void UpdateLifeTime(float dt);
};