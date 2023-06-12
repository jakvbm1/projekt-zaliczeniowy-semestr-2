#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SceneManager.h"

using namespace std;
using namespace sf;

class SceneManager;

class Scene
{
protected:
RenderWindow* window;
SceneManager* manager;

public:
	Scene(SceneManager* manager, RenderWindow* window);

	virtual void handling_events(const sf::Event& event) = 0;
	virtual void render() = 0;

	//update is going to be empty in all classes different that game_scene, because there is nothing that need to be changed overtime in them
	virtual void update(const sf::Time& deltaTime) = 0;
	virtual ~Scene();
};