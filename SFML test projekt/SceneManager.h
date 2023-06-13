#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "scene.h"

class Scene;

class SceneManager
{
private:
	std::unique_ptr<Scene> current_scene;

public:
	SceneManager();

	//handling events, render and update are going to call methods of the same name from current current_scene
	//with that, it is easy to use those method inside Game class, as it contains SceneManager object
	void handling_events(const sf::Event& event);
	void render();
	void update(const sf::Time& deltaTime);
	void set_scene(std::unique_ptr<Scene> newScene);
	~SceneManager();
};
