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

	// Color Button
	SDL_Rect buttonRect{ position.x, position.y, width, height };

	SDL_SetRenderDrawColor(rend, 0xFF, 0x00, 0x00, 0x00);
	SDL_RenderFillRect(rend, &buttonRect);

}