#include "GameEngine.h"

GameEngine::GameEngine(int windowWidth, int windowHeight) {

	InitSDL();
	InitWindowAndRenderer(windowWidth, windowHeight);

}

//Inicializar SDL 
void GameEngine::InitSDL() {
	
	int result = SDL_Init(SDL_INIT_VIDEO);

	if (result < 0) {

		std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
	
	}

}

void GameEngine::InitWindowAndRenderer(int windowWidth, int windowHeight) {
     
	window = SDL_CreateWindow("Serendipity",			//window name
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,	//window position
		windowWidth, windowHeight,						//window size
		SDL_WINDOW_SHOWN);                              //window will be shown by default

	if (window == nullptr) {

		std::cout << "Error creating window: " << SDL_GetError();

	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (window == nullptr) {

		std::cout << "Error creating renderer: " << SDL_GetError();

	}

}

void GameEngine::Update() {

	while (true) {
		//Update Logic


		//Render						  R    G    B
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); //background color

		SDL_RenderClear(renderer);

		//Render objects
		//SDL_RenderCopyex(...)

		SDL_RenderPresent(renderer);

	}

}

void GameEngine::Finish() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

}