#pragma once
#include "Scena.h"
#include "InputManager.h"

class GameplayScene : public Scene {

public:
	GameplayScene()
		: Scene() {}

	void Start() override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;

};