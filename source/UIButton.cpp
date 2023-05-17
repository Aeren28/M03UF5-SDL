#include "UIButton.h"

void UIButton::Render(SDL_Renderer* rend) {

	SDL_Rect dest;

	dest.x = position.x - (int)((float)width * scale.x / 2.0f);
	dest.y = position.y - (int)((float)height * scale.y / 2.0f);

	dest.w = (float)width * scale.x;
	dest.h = (float)height * scale.y;

	SDL_RenderCopyEx(rend, texture,
		NULL, &dest,
		rotation,
		NULL,
		SDL_FLIP_NONE);

	text->Render(rend);

}

void UIButton::GenerateTexture(SDL_Renderer* rend) {

	isHovered ? resourcePath = "resources/button2.png" : resourcePath = "resources/button.png";

	/// Load texture
	//SDL_Surface* surf = IMG_Load("resources/asteroids_spritesheet.png");
	SDL_Surface* surf = IMG_Load(resourcePath.c_str());

	if (surf == nullptr) {

		std::cout << "Cannot load surface: " << SDL_GetError();

	}

	// Generate texture
	texture = SDL_CreateTextureFromSurface(rend, surf);

	if (texture == nullptr) {

		std::cout << "Cannot load texture: " << SDL_GetError();

	}

	// Deleting surface
	SDL_FreeSurface(surf);

}