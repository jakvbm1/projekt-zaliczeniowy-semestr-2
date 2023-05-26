#include "SceneManager.h"

SceneManager::SceneManager()
{
}

void SceneManager::handling_events(const Event& event)
{
	current_scene->handling_events(event);
}

void SceneManager::render()
{
	current_scene->render();
}

void SceneManager::update()
{
	current_scene->update();
}

void SceneManager::set_scene(unique_ptr<Scene> newScene)
{
	current_scene = move(newScene);
}

SceneManager::~SceneManager()
{
}
