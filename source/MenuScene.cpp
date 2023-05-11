#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend); //Parent function
	uiObjects.push_back(
		new UIImage(
			rend,
			Vector2(100, 100), 0.0f, Vector2(1, 1),
			"resources/logo.png",
			255, 255, Vector2(0,0)));

	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(250, 250), 0.0f, Vector2(1.f, 1.f),
			"ASTEROIDS",
			"resources/Hyperspace.ttf"));
}

void MenuScene::Update(float dt) {
	Scene::Update(dt); //Parent function

	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Gameplay";
	}

	if (IM.GetKey(SDLK_h, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Highscore";
	}
}

void MenuScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend); //Parent function

	std::cout << "Main Menu" << std::endl;

}

void MenuScene::Exit() {


}