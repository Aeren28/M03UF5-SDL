#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) 
	: GameObject(renderer) {
	
	position = pos;
	rotation = rot;
	scale = scl;

}

void Spaceship::Update(float dt) {

	UpdateMovement(dt);

}

void Spaceship::UpdateMovement(float dt) {

	velocity = Vector2(10, 10); //Unidades: pixeles/s

	Vector2 velocityDT = velocity * dt;
	position = position + velocityDT;

}

void Spaceship::Render(SDL_Renderer* rend) {

	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = 31;
	source.h = 39;

	SDL_Rect dest;
	dest.x = position.x - (int)((float)source.w * scale.x / 2.0f);
	dest.y = position.y - (int)((float)source.h * scale.y / 2.0f);
	dest.w = (float)source.w * scale.x;
	dest.h= (float)source.h * scale.y;

	SDL_RenderCopyEx(rend, texture, 
		&source, &dest,
		rotation, 
		NULL,           //Punto de rotación: NULL = centrado
		SDL_FLIP_NONE );      //NO hacemos flip de la imagen

}