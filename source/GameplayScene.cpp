#include "GameplayScene.h"

void GameplayScene::Start(SDL_Renderer* rend) {
	
	this->rend = rend;

	currentState = GameplayState::ALIVE;

	currentStateTime = 0.0f;
	lifes = 3;

	rounds = 0;
	score = 0;
	
	Scene::Start(rend);
	
	RespawnSpaceship();

	for (int i = 0; i < rounds + 2; i++)
		objects.push_back(new BigAsteroid(rend));

	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(50, 100), 0.0f, Vector2(1.0f, 1.0f),
			std::to_string(score),
			"resources/Hyperspace.ttf",
			{ 0xFF, 0xFF, 0xFF, 0xFF }));

	uiObjects.push_back(
		new UIImage(
			rend,
			Vector2(93, 50), 0.0f, Vector2(1.0f, 1.0f),
			"resources/asteroids_spritesheet.png",
			31, 39, Vector2(0, 0)));

	uiObjects.push_back(
		new UIImage(
			rend,
			Vector2(62, 50), 0.0f, Vector2(1.0f, 1.0f),
			"resources/asteroids_spritesheet.png",
			31, 39, Vector2(0, 0)));

	uiObjects.push_back(
		new UIImage(
			rend,
			Vector2(31, 50), 0.0f, Vector2(1.0f, 1.0f),
			"resources/asteroids_spritesheet.png",
			31, 39, Vector2(0, 0)));

	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(250, 50), 0.0f, Vector2(1.0f, 1.0f),
			"Round " + std::to_string(rounds + 1),
			"resources/Hyperspace.ttf",
			{ 0xFF, 0xFF, 0xFF, 0xFF }));
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

						score += a->GetScore();

						UIText* t = dynamic_cast<UIText*>(uiObjects[0]);
						t->ChangeText(std::to_string(score));

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

	//Particles Spawn
	if (particlesSpawn.size() > 0) {

		objects.push_back(particlesSpawn[0]);
		objects.push_back(particlesSpawn[1]);
		objects.push_back(particlesSpawn[2]);

		particlesSpawn.clear();

	}

	// BULLET SPAWN
	if (spaceship != nullptr) {

		if (spaceship->BulletShooted())

			objects.push_back(new Bullet(rend, spaceship->GetPosition(), spaceship->GetAngle(), 640.0f));
		
	}

	// CHECK IF THERE ARE ASTEROIDS
	if (asteroidsLeft == 0) {

		rounds++;

		UIText* t = dynamic_cast<UIText*>(uiObjects[4]);

		t->ChangeText("Round " + std::to_string(rounds + 1));

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

	//Particles
	particlesSpawn.push_back(new DeathParticles(rend, spaceship->GetPosition()));
	particlesSpawn.push_back(new DeathParticles(rend, spaceship->GetPosition()));
	particlesSpawn.push_back(new DeathParticles(rend, spaceship->GetPosition()));

	spaceship->Destroy();
	spaceship = nullptr;

	currentState = GameplayState::DEAD;
	currentStateTime = 0.0f;

	int lifesId = uiObjects.size() - lifes - 1;

	UIImage* lifeImage = dynamic_cast<UIImage*>(uiObjects[lifesId]);
	SDL_SetTextureAlphaMod(lifeImage->GetTexture(), 0x7F);

	lifeImage->Render(rend);

	lifes--;

}

void GameplayScene::RespawnSpaceship() {

	for (int i = objects.size() - 1; i >= 0; i--) {

		if (DeathParticles* dp = dynamic_cast<DeathParticles*>(objects[i]))

			dp->Destroy();

	}

	spaceship = new Spaceship(rend, Vector2(GAME_WIDTH / 2.0f, GAME_HEIGHT / 2.0f), 0.0f, Vector2(1.0f, 1.0f));
	
	objects.push_back(spaceship);

	currentState = GameplayState::ALIVE;
	currentStateTime = 0.0f;

}