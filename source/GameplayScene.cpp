#include "GameplayScene.h"

void GameplayScene::Start(SDL_Renderer* rend) {
	
	this->rend = rend;
	
	Scene::Start(rend);

	spaceship = new Spaceship(rend, Vector2(100.f, 100.f), 0.0f, Vector2(1.f, 1.f));
	objects.push_back(spaceship);

	for (int i = 0; i < rounds + 2; i++)
		objects.push_back(new BigAsteroid(rend));

}

void GameplayScene::Update(float dt) {

	currentStateTime += dt;

	int gameObjectsSize = objects.size();

	for (int i = 0; i < gameObjectsSize; i++) {

		//CAST GAMEOBJECT TO ASTEROID
		if (BigAsteroid* a = dynamic_cast<BigAsteroid*>(objects[i])) {
			// CHECK IF ASTEROID HAS TO BE DESTROYED
			if (a->IsPendingDestroy()) {

				objects.push_back(new MediumAsteroid(rend, a->GetPosition()));
				objects.push_back(new MediumAsteroid(rend, a->GetPosition()));

			}

		}

		if (MediumAsteroid* a = dynamic_cast<MediumAsteroid*>(objects[i])) {

			if (a->IsPendingDestroy()) {

				objects.push_back(new SmallAsteroid(rend, a->GetPosition()));
				objects.push_back(new SmallAsteroid(rend, a->GetPosition()));

			}

		}

	}

	//DESTROYERS
	for (auto it = objects.begin(); it != objects.end(); it++) {
		//CAST OBJECTS TO BULLET
		if (Bullet* b = dynamic_cast<Bullet*>(*it)) {
			//CHECK IF BULLET HAS TO BE DESTROYED
			if (b->IsPendingDestroy())
				b->Destroy();

		}

	}

	Scene::Update(dt);

	int asteroidsLeft = 0;

	//COLISIONS

	for (auto it = objects.begin(); it != objects.end(); it++) {
		//it = puntero a objeto

		//CAST OBJECTS TO BULLET
		if (Bullet* b = dynamic_cast<Bullet*>(*it)) {
			//If bullet collides with asteroid
				//destroy bullet
				//destroy asteroid

			for (auto it2 = objects.begin(); it2 != objects.end(); it2++) {

				if (Asteroid* a = dynamic_cast<Asteroid*>(*it2)) {

					Vector2 bulletToAsteroid = a->GetPosition() - b->GetPosition();
					float distanceSquared = bulletToAsteroid.x * bulletToAsteroid.x + bulletToAsteroid.y * bulletToAsteroid.y;
					float squareRadiusSum = a->GetRadius() + b->GetRadius();			// bulletRadius + asteroidRadius

					squareRadiusSum *= squareRadiusSum;

					if (distanceSquared < squareRadiusSum) {
						b->Destroy();
						a->Destroy();

					}

				}

			}

		}


		//CAST OBJECT TO ASTEROID
		if (Asteroid* a = dynamic_cast<Asteroid*>(*it)) {
			//If asteroid collides with spaceship
				//destroy asteroid
				//destroy spaceship

			asteroidsLeft++;

			if (spaceship != nullptr && currentStateTime > stateTimeThreshold) {

				Vector2 spaceshiptToAsteroid = a->GetPosition() - spaceship->GetPosition();
				float distanceSquared = spaceshiptToAsteroid.x * spaceshiptToAsteroid.x + spaceshiptToAsteroid.y * spaceshiptToAsteroid.y;
				float squareRadiusSum = a->GetRadius() * 0.5f + spaceship->GetRadius() * 0.5f;		// playerRadius + asteroidRadius

				squareRadiusSum *= squareRadiusSum;

				if (distanceSquared < squareRadiusSum) {

					a->Destroy();
					DestroySpaceship();

				}

			}

		}

	}

	// BULLET SPAWN
	if (spaceship != nullptr) {

		if (spaceship->BulletShooted())

			objects.push_back(new Bullet(rend, spaceship->GetPosition(), spaceship->GetAngle(), 640.0f));
		
	}

	// CHECK IF THERE ARE ASTEROIDS
	if (asteroidsLeft == 0) {

		rounds++;

		for (int i = 0; i < rounds + 2; i++) {

			objects.push_back(new BigAsteroid(rend));
		
		}

	}

	if (currentState == GameplayState::DEAD && currentStateTime > stateTimeThreshold) {
			
		if (lifes != 0)
			RespawnSpaceship();

		else {

			finished = true;
			targetScene = "Main Menu";
			
		}

	}

}

void GameplayScene::DestroySpaceship() {

	spaceship->Destroy();
	spaceship = nullptr;

	currentState = GameplayState::DEAD;
	currentStateTime = 0.0f;

	lifes--;

}

void GameplayScene::RespawnSpaceship() {

	spaceship = new Spaceship(rend, Vector2(GAME_WIDTH / 2.0f, GAME_HEIGHT / 2.0f), 0.0f, Vector2(1.0f, 1.0f));
	
	objects.push_back(spaceship);

	currentState = GameplayState::ALIVE;
	currentStateTime = 0.0f;

}