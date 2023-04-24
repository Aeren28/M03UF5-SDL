#pragma once
#include "Scena.h"

class MenuScene : public Scene {

public:
	MenuScene()
		: Scene() {}
	
	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;

};