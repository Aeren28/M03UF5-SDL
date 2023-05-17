#pragma once

#include "Scena.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "SmallAsteroid.h"
#include "Bullet.h"

enum GameplayState { ALIVE, DEAD };

class GameplayScene : public Scene {

public:
	GameplayScene()
		: Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;

private:
	Spaceship* spaceship;
	SDL_Renderer* rend;

	GameplayState currentState;

	int lifes;
	float currentStateTime;
	const float stateTimeThreshold = 3.0f;
	int rounds = 0;

	void DestroySpaceship();
	void RespawnSpaceship();

};