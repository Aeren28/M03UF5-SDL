#include "GameplayScene.h"

void GameplayScene::Start() {
	Scene::Start();

}

void GameplayScene::Update(float dt) {
	Scene::Update(dt);

	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Main Menu";
	}

	if (IM.GetKey(SDLK_b, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Highscore";
	}

}

void GameplayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

	std::cout << "GamePlay" << std::endl;

}

void GameplayScene::Exit() {


}