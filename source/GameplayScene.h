#pragma once
#include "Scena.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "SmallAsteroid.h"
#include "Bullet.h"

class GameplayScene : public Scene {

public:
	GameplayScene()
		: Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;

private:
	Spaceship* spaceship;
	SDL_Renderer* rend;
	int rounds = 0;

};