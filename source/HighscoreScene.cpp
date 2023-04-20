#include "HighscoreScene.h"

void HighscoreScene::Start() {


}

void HighscoreScene::Update(float dt) {
	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Gameplay";
	}

}

void HighscoreScene::Render(SDL_Renderer* rend) {

	std::cout << "HighscoreScene" << std::endl;

}

void HighscoreScene::Exit() {


}