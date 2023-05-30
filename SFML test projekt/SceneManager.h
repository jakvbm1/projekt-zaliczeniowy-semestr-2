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
	void handling_events(const sf::Event& event);
	void render();
	void update(const sf::Time& deltaTime);
	void set_scene(std::unique_ptr<Scene> newScene);
	~SceneManager();
};
