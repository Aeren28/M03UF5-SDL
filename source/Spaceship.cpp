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

	if (IM.GetKey(SDLK_UP, HOLD) || IM.GetKey(SDLK_UP, DOWN)) {
		Vector2 dir;
		float rotationInRadiants = rotation * (M_PI / 180.f);
		
		dir.x = cos(rotationInRadiants);
		dir.y = sin(rotationInRadiants);
  
		velocity = velocity + (dir * dt * 50.0f);   //Unidades: pixeles/s
	}

	if (IM.GetKey(SDLK_RIGHT, HOLD) || IM.GetKey(SDLK_RIGHT, DOWN)) {
		rotation += dt * 100; //Units: º/s
	
	}
	else if (IM.GetKey(SDLK_LEFT, HOLD) || IM.GetKey(SDLK_LEFT, DOWN)) {
		rotation -= dt * 100;
	}

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
		90.0f + rotation, 
		NULL,           //Punto de rotación: NULL = centrado
		SDL_FLIP_NONE );      //NO hacemos flip de la imagen

}