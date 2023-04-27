#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

#include "Vector2.h"
#include "Utils.h"

class GameObject {

public:
	GameObject(SDL_Renderer* renderer, int w, int h);
	~GameObject();

	virtual void Update(float dt) = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;

protected:
	Vector2 position;
	Vector2 scale;

	float rotation;
	
	SDL_Texture* texture;
	int width, height;

};