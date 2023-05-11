#pragma once

#include "GameObject.h"
#include "InputManager.h"

class Spaceship : public GameObject {

public:
	
	Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl);

	bool BulletShooted();
	void Update(float dt) override;

private:

	bool canShot;
	bool wantsToShot;

	float lastShotTime;
	float maxShotTime;

	void UpdateMovement(float dt) override;
	void UpdateShot(float dt);

};