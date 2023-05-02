#include "GameplayScene.h"

void GameplayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);

	objects.push_back(new Spaceship(rend, Vector2(100.f, 100.f), 0.0f, Vector2(1.f, 1.f)));
	
	for(int i = 0; i < 10; i++)
		objects.push_back(new Asteroid(rend));
}

void GameplayScene::Update(float dt) {
	Scene::Update(dt);

	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		//Transition code
		objects[0]->Destroy();
	}

}

void GameplayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

	std::cout << "GamePlay" << std::endl;

}

void GameplayScene::Exit() {

	for (auto it = objects.begin(); it != objects.end(); it++) {

		delete(*it);

	}

	objects.clear();

}