#include "UIImage.h"

void UIImage::Render(SDL_Renderer* rend) {

	SDL_Rect source;
	source.x = padding.x;
	source.y = padding.y;
	source.w = width;
	source.h = height;

	SDL_Rect dest;
	dest.x = position.x - (int)((float)source.w * scale.x / 2.0f);
	dest.y = position.y - (int)((float)source.h * scale.y / 2.0f);
	dest.w = (float)source.w * scale.x;
	dest.h = (float)source.h * scale.y;

	SDL_RenderCopyEx(rend, texture,
		&source, &dest,
		rotation,
		NULL,           //Punto de rotación: NULL = centrado
		SDL_FLIP_NONE);      //NO hacemos flip de la imagen

}

void UIImage::GenerateTexture(SDL_Renderer* rend) {

	//Load the texture
	SDL_Surface* surf = IMG_Load("resources/asteroids_spritesheet.png");

	if (surf == nullptr) {

		std::cout << "Cannot load surface: " << SDL_GetError();

	}

	texture = SDL_CreateTextureFromSurface(rend, surf);

	if (texture == nullptr) {

		std::cout << "Cannot load texture: " << SDL_GetError;

	}

	SDL_FreeSurface(surf);

}