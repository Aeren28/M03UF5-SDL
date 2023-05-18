#pragma once

#include "GameObject.h"

class Enemy : public GameObject {

public:
	Enemy(SDL_Renderer* rend);
	int GetScore() { return score; }

protected:
	int score;

};