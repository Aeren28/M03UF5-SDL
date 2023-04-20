#pragma once
#include "Scena.h"
#include "InputManager.h"

class HighscoreScene : public Scene {

public:
	HighscoreScene()
		: Scene() {}

	void Start() override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;

};