#pragma once
#include <SDL.h>
#include <string>

#include "Vector2.h"

class UIObject {

public:

	UIObject(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl)
		: position(pos), rotation(rot), scale(scl) {}

	~UIObject() { SDL_DestroyTexture(texture); }

	virtual void Update(float dt) = 0;
	virtual void Render(SDL_Renderer* rend) = 0;

protected:

	virtual void GenerateTexture(SDL_Renderer* rend) = 0;

	Vector2 position;
	float rotation;
	Vector2 scale;

	SDL_Texture* texture;
	int width, height;
	Vector2 padding;

};