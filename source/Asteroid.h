#pragma once

#include "GameObject.h"
#include "InputManager.h"

class Asteroid : public GameObject {

public:
	Asteroid(SDL_Renderer* rend);
	int GetScore() { return score; }

protected:
	int score;

};