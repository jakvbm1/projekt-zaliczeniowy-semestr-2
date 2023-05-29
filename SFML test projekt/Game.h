#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"scene.h"
#include"SceneManager.h"
#include"menu.h"
#include"Enemy.h"

using namespace sf;
using namespace std;

class Game
{
private:
	SceneManager manager;
	RenderWindow window;
	Clock frameClock;

public:
	Game(string title);
	void play();
	~Game();
};

