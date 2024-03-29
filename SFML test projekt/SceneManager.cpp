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

void SceneManager::update(const sf::Time& deltaTime)
{
	current_scene->update(deltaTime);
}

void SceneManager::set_scene(unique_ptr<Scene> newScene)
{
	//old scene object is automatically deleted so it isn't stored in memory unnecesarilly 
	current_scene = move(newScene);
}


SceneManager::~SceneManager()
{
}
