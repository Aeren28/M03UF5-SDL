#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend); //Parent function
	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(250, 50), 0.0f, Vector2(1.5f, 1.5f),
			"ASTEROIDS",
			"resources/Hyperspace.ttf",
			{ 0xFF, 0xFF, 0x00, 0xFF }));

	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(250, 400), 0.0f, Vector2(0.9f, 0.9f),
			"Hugo Cifuentes",
			"resources/Hyperspace.ttf",
			{ 0xFF, 0xFF, 0x00, 0xFF }));

	uiObjects.push_back(
		new UIText(
			rend,
			Vector2(250, 450), 0.0f, Vector2(0.9f, 0.9f),
			"Nerea Fernández",
			"resources/Hyperspace.ttf",
			{ 0xFF, 0xFF, 0x00, 0xFF }));

	uiObjects.push_back(
		new UIButton(
			rend,
			Vector2(250, 150), 0.0f, Vector2(0.99f, 0.99f), 260, 80,
			"GamePlay",
			"resources/Hyperspace.ttf",
			{ 0xFF, 0xFF, 0x00, 0xFF }));

	uiObjects.push_back(
		new UIButton(
			rend,
			Vector2(250, 200), 0.0f, Vector2(0.99f, 0.99f), 260, 80,
			"HighScores",
			"resources/Hyperspace.ttf",
			{ 0xFF, 0xFF, 0xFF, 0xFF }));

	uiObjects.push_back(
		new UIButton(
			rend,
			Vector2(250, 250), 0.0f, Vector2(0.99f, 0.99f), 260, 80,
			"Exit",
			"resources/Hyperspace.ttf",
			{ 0xFF, 0xFF, 0xFF, 0xFF }));
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