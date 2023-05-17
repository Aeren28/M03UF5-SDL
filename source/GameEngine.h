#pragma once

#include <SDL.h>

#include <iostream>
#include <stdlib.h>

#include "InputManager.h"
#include "MenuScene.h"
#include "GameplayScene.h"
#include "HighscoreScene.h"

class GameEngine {

public:
	GameEngine(int windowWidth, int windowHeight);

	void Update();
	void Finish();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	void InitSDL();
	void InitWindowAndRenderer(int windowWidth, int windowHeight);
	
};