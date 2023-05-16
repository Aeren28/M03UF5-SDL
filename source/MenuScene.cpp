#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend); //Parent function
	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(250, 200), 0.0f, Vector2(1.f, 1.f),
			"ASTEROIDS",
			"resources/Hyperspace.ttf"));

	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(250, 400), 0.0f, Vector2(1.f, 1.f),
			"Hugo Cifuentes",
			"resources/Hyperspace.ttf"));

	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(250, 450), 0.0f, Vector2(1.f, 1.f),
			"Nerea Fernández",
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