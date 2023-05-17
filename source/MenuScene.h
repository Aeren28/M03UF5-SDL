#pragma once

#include "Scena.h"
#include "UIImage.h"
#include "UIText.h"
#include "UIButton.h"

class MenuScene : public Scene {

public:
	MenuScene()
		: Scene() {}
	
	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;

};