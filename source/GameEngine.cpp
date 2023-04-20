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

	//---- TIME CONTROL
	float dt = 0.0f;
	float lastTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();
	
	const int FPS = 60;
	const float frameTime = 1.0f / (float)FPS;

	//---- SCENES
	std::unordered_map<std::string, Scene*> gameScenes;

	gameScenes["Main Menu"] = new MenuScene();
	gameScenes["Gameplay"] = new GameplayScene();
	//gameScenes["Highscores"] = new HighscoreScene();

	Scene* currentScene = gameScenes["Main Menu"];

	while (!IM.GetQuit()) {
		// ---- DELTA TIME CONTROL
		float currentTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();
		dt += currentTime - lastTime;
		lastTime = currentTime;

		if (dt > frameTime) {

			//Update Input
			IM.Listen();

			//Update Logic
			currentScene->Update(dt);

			//Render
			SDL_RenderClear(renderer);

			//Render objects
			currentScene->Render(renderer);

			SDL_RenderPresent(renderer);

			//Scene transition
			if (currentScene->IsFinished()) {

				currentScene->Exit();
				currentScene = gameScenes[currentScene->GetTargetScene()];
				currentScene->Start();

			}

			dt -= frameTime;
		}
	}

}

void GameEngine::Finish() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

}