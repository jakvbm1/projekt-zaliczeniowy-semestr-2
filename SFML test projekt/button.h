#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

extern sf::Color vanilla;
extern sf::Color intense_vanilla;
extern sf::Color brown;

class Button : public Drawable
{
	RectangleShape shape;
	Text text;
	Font font;

	Color color;
	Color color_when_mouse_on;
	Color outline_color;

	SoundBuffer buff;
	Sound click_sound;

public:
	Button();
	void pressed();
	void set_parameters(int x, int y, string text, int pos_x, int pos_y);
	bool is_mouse_on(Vector2i mouse_position);
	void mouse_on_highlight(Vector2i mouse_position);


	// Odziedziczono za poœrednictwem elementu Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const override;


};

