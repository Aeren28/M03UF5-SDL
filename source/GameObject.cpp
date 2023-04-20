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

void GameObject::Update(float dt) {

}

void GameObject::Render(SDL_Renderer* renderer) {

	SDL_Rect source{ 0, 0,	   //Position
					250/2, 300 //Size
	};

	//                     x    y    w    h
	SDL_Rect destination{ position.x, position.y, //Position
					source.w * scale.x , source.h * scale.y };
	
	SDL_RenderCopy(renderer, texture, &source, &destination);
 
}