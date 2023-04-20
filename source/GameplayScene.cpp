#include "GameplayScene.h"

void GameplayScene::Start() {


}

void GameplayScene::Update(float dt) {
	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Main Menu";
	}

}

void GameplayScene::Render(SDL_Renderer* rend) {

	std::cout << "GamePlay" << std::endl;

}

void GameplayScene::Exit() {


}