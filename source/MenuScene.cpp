#include "MenuScene.h"

void MenuScene::Start() {
	Scene::Start(); //Parent function

}

void MenuScene::Update(float dt) {
	Scene::Update(dt); //Parent function

	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Gameplay";
	}

}

void MenuScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend); //Parent function

	std::cout << "Main Menu" << std::endl;

}

void MenuScene::Exit() {


}