#pragma once
#include "GameObject.h"

class Bullet : public GameObject {

public:

	Bullet(SDL_Renderer* renderer, Vector2 pos, float angle);
	
	bool ToDestroy() { return toDestroy; }

private:

	float timeToLive = 0.8f;
	float timeAlive = 0.0f;

	bool toDestroy = false;

	void Update(float dt) override;
};