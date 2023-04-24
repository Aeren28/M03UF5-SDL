#pragma once
#include <vector>

#include "GameObject.h"
#include "InputManager.h"

class Scene {

public:
	Scene() = default;

	virtual void Start(SDL_Renderer* rend) {
		finished = false;
	}

	virtual void Update(float dt) {
		for (auto it = objects.begin(); it != objects.end(); it++)
			(* it)->Update(dt);
	}

	virtual void Render(SDL_Renderer* rend) {
		for (auto it = objects.begin(); it != objects.end(); it++)
			(* it)->Render(rend);
	}

	virtual void Exit() = 0;

	bool IsFinished() { return finished; }
	std::string GetTargetScene() { return targetScene; }

protected:
	std::vector<GameObject*>objects;

	bool finished = false;
	std::string targetScene;
};