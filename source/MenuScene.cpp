#include "MenuScene.h"

void MenuScene::Start() {


}

void MenuScene::Update(float dt) {
	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Gameplay";
	}

}

void MenuScene::Render(SDL_Renderer* rend) {

	std::cout << "Main Menu" << std::endl;

}

void MenuScene::Exit() {


}