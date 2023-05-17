#pragma once

#include "UIObject.h"
#include "UIText.h"

class UIButton : public UIObject {

public:

	UIButton(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, int w, int h, std::string txt, std::string path, SDL_Color col)
		: UIObject(rend, pos, rot, scl) {

		text = new UIText(rend, pos, rot, scl, txt, path, col);
		width = w;
		height = h;

		GenerateTexture(rend);

	}

	void Update(float dt) override {}
	void Render(SDL_Renderer* rend) override;

protected:

	bool isHovered;
	bool isClicked;

	UIText* text;
	SDL_Renderer* renderer;

	void GenerateTexture(SDL_Renderer* rend) override;

};