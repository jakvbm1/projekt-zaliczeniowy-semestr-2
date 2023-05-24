#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"button.h"
#include<math.h>


using namespace std;
using namespace sf;

class Menu
{
private:
	//window
	RenderWindow* window;
	VideoMode vm;

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
	Mouse mouse;

	Event event;

	void initialize_vars();
	void initialize_window();
	void initialize_background();


public:

	const bool is_open() const;


	Menu();
	~Menu();
	void pollEvents();
	void update();
	void render();


};
