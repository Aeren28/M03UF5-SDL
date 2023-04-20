#include "HighscoreScene.h"

void HighscoreScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);

}

void HighscoreScene::Update(float dt) {
	Scene::Update(dt);

	if (IM.GetKey(SDLK_SPACE, DOWN)) {
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