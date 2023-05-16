#pragma once
#include <vector>

#include "GameObject.h"
#include "InputManager.h"
#include "UIObject.h"

class Scene {

public:
	Scene() = default;

	virtual void Start(SDL_Renderer* rend) {
		finished = false;
	}

	virtual void Update(float dt) {
		for (int i = objects.size() - 1; i >= 0; i--) {

			if (objects[i]->IsPendingDestroy()) {

				delete objects[i];
				objects.erase(objects.begin() + i);

			}
		}

		//GAME
		for (auto it = objects.begin(); it != objects.end(); it++)
			(* it)->Update(dt);

		//UI
		for (auto it = uiObjects.begin(); it != uiObjects.end(); it++)
			(*it)->Update(dt);
	}

	virtual void Render(SDL_Renderer* rend) {
		//GAME
		for (auto it = objects.begin(); it != objects.end(); it++)
			(* it)->Render(rend);

		//UI
		for (auto it = uiObjects.begin(); it != uiObjects.end(); it++)
			(*it)->Render(rend);
	}

	virtual void Exit() {

		for (int i = objects.size() - 1; i >= 0; i--) {
			delete objects[i];
		}
		for (int i = uiObjects.size() - 1; i >= 0; i--) {
			delete uiObjects[i];
		}

		objects.clear();
		uiObjects.clear();
	}

	bool IsFinished() { return finished; }
	std::string GetTargetScene() { return targetScene; }

protected:
	std::vector<GameObject*> objects;
	std::vector<UIObject*> uiObjects;

	bool finished = false;
	std::string targetScene;
};