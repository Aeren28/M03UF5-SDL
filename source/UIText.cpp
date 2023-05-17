#include "UIText.h"

void UIText::Render(SDL_Renderer* rend) {

	SDL_Rect dest;

	dest.x = position.x - (int)((float)width * scale.x / 2.0f);
	dest.y = position.y - (int)((float)height * scale.y / 2.0f);

	dest.w = (float)width * scale.x;
	dest.h = (float)height * scale.y;

	SDL_RenderCopyEx(rend, texture,
		NULL, &dest,
		rotation,
		NULL,           //Punto de rotación: NULL = centrado
		SDL_FLIP_NONE);      //NO hacemos flip de la imagen

}

void UIText::GenerateTexture(SDL_Renderer* rend) {
	
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), 28);
	SDL_Color color{ 0xFF, 0xFF, 0xFF, 0xFF };
	
	SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), color); //fuente, texto, color
												                         //TTF_Font*, texto, R-value
	if (surf == nullptr)
		std::cout << "Something went wrong generating the text surface" << SDL_GetError();

	texture = SDL_CreateTextureFromSurface(rend, surf);

	if (texture == nullptr)
		std::cout << "Something went wrong generating the text texture" << SDL_GetError();

	width = surf->w;
	height = surf->h;

	SDL_FreeSurface(surf);
	TTF_CloseFont(font);

}