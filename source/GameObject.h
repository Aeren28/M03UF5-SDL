#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

#include "Vector2.h"

class GameObject {

public:
	GameObject(SDL_Renderer* renderer);

	void Update(float dt);
	void Render(SDL_Renderer* renderer);

private:
	Vector2 position;
	Vector2 scale;

	float rotation;
	
	SDL_Texture* texture;

};