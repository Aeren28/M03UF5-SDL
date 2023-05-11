#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) 
	: GameObject(renderer, 31, 39, Vector2(0, 0)) {
	
	position = pos;
	rotation = rot;
	scale = scl;

	velocity = Vector2();
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 1.0f;
	angularDrag = 2.5;

	accelerationFactor = 200.0f;		//Px  /sec^2
	angularAccelerationFactor = 18000.0f; //Degs/sec^2


	canShot = false;
	wantsToShot = false;

	maxShotTime = 0.25f;
	lastShotTime = maxShotTime;

}

void Spaceship::Update(float dt) {

	GameObject::Update(dt);
	UpdateShot(dt);

}

void Spaceship::UpdateMovement(float dt) {

	acceleration = Vector2();

	if (IM.GetKey(SDLK_UP, HOLD) || IM.GetKey(SDLK_UP, DOWN)) {
		Vector2 dir;
		float rotationInRadiants = rotation * (M_PI / 180.f);
		
		dir.x = cos(rotationInRadiants);
		dir.y = sin(rotationInRadiants);
  
		acceleration = dir * accelerationFactor;   //Unidades: pixeles/s
	}

	angularAcceleration = 0;

	if (IM.GetKey(SDLK_RIGHT, HOLD) || IM.GetKey(SDLK_RIGHT, DOWN)) {
		angularAcceleration = dt * angularAccelerationFactor; //Units: º/s
	
	}
	else if (IM.GetKey(SDLK_LEFT, HOLD) || IM.GetKey(SDLK_LEFT, DOWN)) {
		angularAcceleration = dt * -angularAccelerationFactor;
	}

	GameObject::UpdateMovement(dt);
}

void Spaceship::UpdateShot(float dt) {

	// Update Time
	lastShotTime += dt;

	// Can Shoot
	canShot = lastShotTime >= maxShotTime;

	// Wants to Shot
	wantsToShot = IM.GetKey(SDLK_SPACE, DOWN) || IM.GetKey(SDLK_SPACE, HOLD);
}

bool Spaceship::BulletShooted() {

	if (canShot && wantsToShot) {
		lastShotTime = 0.0f;
		return true;
	}

	return false;

}