#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) 
	: GameObject(renderer) {
	
	position = pos;
	rotation = rot;
	scale = scl;

	velocity = Vector2();
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 1.0f;
	angularDrag = 2.5;

	accelerationFactor = 500.0f;		//Px  /sec^2
	angularAccelerationFactor = 18000.0f; //Degs/sec^2

}

void Spaceship::Update(float dt) {

	UpdateMovement(dt);
	ClampPosition();

}

void Spaceship::UpdateMovement(float dt) {

	acceleration = Vector2();

	if (IM.GetKey(SDLK_UP, HOLD) || IM.GetKey(SDLK_UP, DOWN)) {
		Vector2 dir;
		float rotationInRadiants = rotation * (M_PI / 180.f);
		
		dir.x = cos(rotationInRadiants);
		dir.y = sin(rotationInRadiants);
  
		acceleration = dir * accelerationFactor;   //Unidades: pixeles/s
	}

	angularAcceleration = 0;

	if (IM.GetKey(SDLK_RIGHT, HOLD) || IM.GetKey(SDLK_RIGHT, DOWN)) {
		angularAcceleration = dt * angularAccelerationFactor; //Units: º/s
	
	}
	else if (IM.GetKey(SDLK_LEFT, HOLD) || IM.GetKey(SDLK_LEFT, DOWN)) {
		angularAcceleration = dt * -angularAccelerationFactor;
	}

	//UPDATE VELOCITY AND ANGULAR VELOCITY
	velocity = velocity + acceleration * dt;
	angularVelocity = angularVelocity + angularAcceleration * dt;

	//DRAG
	velocity = velocity * (1.0 - linearDrag * dt);
	angularVelocity = angularVelocity * (1.0 - angularDrag * dt);

	//UPDATE POSITION AND ROTATION
	position = position + velocity * dt;
	rotation = rotation + angularVelocity * dt;

}

void Spaceship::ClampPosition() {
	if (position.x > GAME_WIDTH)
		position.x -= GAME_WIDTH;

	if (position.x < 0.0f)
		position.x += GAME_WIDTH;

	if (position.y > GAME_HEIGHT)
		position.y -= GAME_HEIGHT;

	if (position.y < 0.0f)
		position.y += GAME_HEIGHT;
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