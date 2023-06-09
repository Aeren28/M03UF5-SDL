#pragma once

#include "UIObject.h"
#include "UIText.h"

#include <SDL_image.h>

class UIButton : public UIObject {

public:

	UIButton(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, int w, int h, std::string txt, std::string path, SDL_Color col)
		: UIObject(rend, pos, rot, scl) {

		text = new UIText(rend, pos, rot, scl, txt, path, col);
		width = w;
		height = h;

		resourcePath = "resources/button.png";
		renderer = rend;

		GenerateTexture(rend);

	}

	void Update(float dt) override {}
	void Render(SDL_Renderer* rend) override;

	bool IsHovering() { return isHovered; }

	void Hover() { isHovered = true; }
	void IsNotHover() { isHovered = false; }

	Vector2 GetPosition() { return position + padding; }

	int GetWidth() { return width; }
	int GetHeight() { return height; }

	void ChangeTexture() {

		SDL_DestroyTexture(texture);
		GenerateTexture(renderer);

	}

	std::string GetText() { return text->GetText(); }

protected:

	bool isHovered;
	bool isClicked;

	UIText* text;
	SDL_Renderer* renderer;

	std::string resourcePath;

	void GenerateTexture(SDL_Renderer* rend) override;

};