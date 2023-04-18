#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer) {

	position = Vector2();
	scale = Vector2(1.f, 1.f);
	
	rotation = 0.f;

	//Load the texture
	SDL_Surface* surf = IMG_Load("resources/logo.png");

	if (surf == nullptr) {

		std::cout << "Cannot load surface: " << SDL_GetError();
	
	}

	texture = SDL_CreateTextureFromSurface(renderer, surf);

	if (texture == nullptr) {

		std::cout << "Cannot load texture: " << SDL_GetError;

	}

	SDL_FreeSurface(surf);

}