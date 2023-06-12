#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

//these colors are going to be used in all scene classes, so it is easier to have them in button.h, as all scene classes include that file
extern sf::Color vanilla;
extern sf::Color intense_vanilla;
extern sf::Color brown;
extern sf::Font main_font;

//all classes with objects that are meant to be drawn has to inherit from Drawable virtual class 
class Button : public Drawable
{
	RectangleShape shape;
	Text text;
	Font font;

	SoundBuffer buff;
	Sound click_sound;

public:
	Button();
	void pressed();
	void set_parameters(int x, int y, string mes, int pos_x, int pos_y);
	bool is_mouse_on(Vector2i mouse_position);
	void mouse_on_highlight(Vector2i mouse_position);


	// Odziedziczono za poœrednictwem elementu Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const override;


};

