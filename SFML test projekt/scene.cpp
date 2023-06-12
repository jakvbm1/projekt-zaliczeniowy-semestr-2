#include "scene.h"

Scene::Scene(SceneManager* manager, RenderWindow* window)
{
	this->manager = manager;
	this->window = window;
}

Scene::~Scene()
{
}
