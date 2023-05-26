#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"button.h"
#include<math.h>
#include "scene.h"
#include"SceneManager.h"
#include"credits.h"

using namespace std;
using namespace sf;

class Menu : public Scene
{
private:

	//variables used in menu
	Texture background_t;
	Sprite background;
	Font main_font;
	Button* start_button;
	Button* exit_button;
	Button* rules_button;
	Button* credits_button;
	Text title;
	Text authors;

	void initialize_vars();
	void initialize_background();


public:


	Menu(SceneManager* manager, RenderWindow* window);
	~Menu();
	void handling_events(const sf::Event& event);
	void update();
	void render();


};
