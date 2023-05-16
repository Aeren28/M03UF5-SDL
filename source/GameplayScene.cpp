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
	
	//CHECK IF THERE ARE ASTEROIDS
	int asteroids = 0;

	for (auto it = objects.begin(); it != objects.end(); it++) {
		//CAST OBJECTS TO ASTEROID

		if (Asteroid* a = dynamic_cast<Asteroid*>(*it)) {
			asteroids++;

		}

	}

	if (asteroids == 0) {
		rounds++;

		for (int i = 0; i < rounds + 2; i++) {
			objects.push_back(new BigAsteroid(rend));

		}

	}

	//SPAWNERS
	if (spaceship != nullptr) {
		if(spaceship->BulletShooted())
			objects.push_back(new Bullet(rend, spaceship->GetPosition(), spaceship->GetAngle(), 650.f));

	}

	for (int i = 0; i < objects.size(); i++) {
		//CAST OBJECTS TO ASTEROID
		if (Asteroid* a = dynamic_cast<BigAsteroid*>(objects[i])) {
			//CHECK IF ASTEROID HAS TO BE DESTROYED
			if (a->IsPendingDestroy()) {
				objects.push_back(new MediumAsteroid(rend, a->GetPosition()));
				objects.push_back(new MediumAsteroid(rend, a->GetPosition()));

			}

		}

		if (Asteroid* a = dynamic_cast<MediumAsteroid*>(objects[i])) {
			//CHECK IF ASTEROID HAS TO BE DESTROYED
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

	//COLISIONS

	for (auto it = objects.begin(); it != objects.end(); it++) {
		//it = puntero a objeto

		//CAST OBJECTS TO BULLET
		if (Bullet* b = dynamic_cast<Bullet*>(*it)) {
			//If bullet collides with asteroid
				//destroy bullet
				//destroy asteroid
			for (auto it = objects.begin(); it != objects.end(); it++) {

				if (spaceship != nullptr) {
					if (Asteroid* a = dynamic_cast<Asteroid*>(*it)) {
						
						Vector2 bulletToAsteroid = a->GetPosition() - b->GetPosition();
						
						float distanceSquared = bulletToAsteroid.x * bulletToAsteroid.x + bulletToAsteroid.y * bulletToAsteroid.y;
						float squareRadiusSum = a->GetRadius() + b->GetRadius();    // bulletRadius + asteroidRadius
						squareRadiusSum *= squareRadiusSum;

						if (distanceSquared < squareRadiusSum) {
							b->Destroy();
							a->Destroy();
						}
					}
				}

			}

		}

	}

	for(auto it=objects.begin(); it!=objects.end();it++){
		//CAST OBJECT TO ASTEROID
		if (Asteroid* a = dynamic_cast<Asteroid*>(*it)) {
			//If asteroid collides with spaceship
				//destroy asteroid
				//destroy spaceship
			Vector2 spaceshipToAsteroid = a->GetPosition() - spaceship->GetPosition();
			float distanceSquared = spaceshipToAsteroid.x * spaceshipToAsteroid.x + spaceshipToAsteroid.y * spaceshipToAsteroid.y;
			float squaredRadiusSum = a->GetRadius() + spaceship->GetRadius();	 //playerRadius + asteroidRadius
			squaredRadiusSum *= squaredRadiusSum;

			if (distanceSquared < squaredRadiusSum) {
				spaceship->Destroy();
				spaceship = nullptr;
				a->Destroy();
				finished = true;
				targetScene = "Main Menu";

			}

		}

	}

}

void GameplayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

	std::cout << "GamePlay" << std::endl;

}