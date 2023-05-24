#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"SceneManager.h"

using namespace std;
using namespace sf;

class SceneManager;

class Scene
{
protected:
RenderWindow* window;
SceneManager* manager;

public:
	Scene();
	virtual void pollEvents(const sf::Event& event) = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual ~Scene() = 0;
};