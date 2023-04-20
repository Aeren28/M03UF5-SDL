#pragma once
#include <vector>

#include "GameObject.h"

class Scene {

public:
	Scene() = default;

	virtual void Start() = 0;

	virtual void Update(float dt) {
		for (auto it = objects.begin(); it != objects.end(); it++)
			it->Update(dt);
	}

	virtual void Render(SDL_Renderer* rend) {
		for (auto it = objects.begin(); it != objects.end(); it++)
			it->Render(rend);
	}

	virtual void Exit() = 0;

protected:
	std::vector<GameObject>objects;

	bool finished = false;
	std::string targetScene;
};