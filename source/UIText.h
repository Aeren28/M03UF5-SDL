#pragma once
#include "UIObject.h"
#include <SDL_ttf.h>
#include <iostream>

class UIText : public UIObject {

public:

	UIText(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, std::string txt, std:: string path)
		: UIObject(rend, pos, rot, scl), text(txt), fontPath(path) {
		GenerateTexture(rend);
	}

	void Update(float dt) override {}
	void Render(SDL_Renderer* rend) override;

protected:
	
	void GenerateTexture(SDL_Renderer* rend) override;

	std::string text;
	std::string fontPath;

};