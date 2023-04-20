#include "HighscoreScene.h"

void HighscoreScene::Start() {
	Scene::Start();

}

void HighscoreScene::Update(float dt) {
	Scene::Update(dt);

	if (IM.GetKey(SDLK_b, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Gameplay";
	}

	if (IM.GetKey(SDLK_a, DOWN)) {
		//Transition code
		finished = true;
		targetScene = "Main Menu";
	}

}

void HighscoreScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

	std::cout << "Highscore" << std::endl;

}

void HighscoreScene::Exit() {


}