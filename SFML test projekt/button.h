#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class Button : public Drawable
{
	RectangleShape shape;
	Text text;
	Font font;

	Color color;
	Color color_when_mouse_on;
	Color color_when_clicked;

public:
	Button(float width, float height, float x, float y, string message, Color c_stand = Color::White, Color c_mouse_on = Color::Yellow, Color c_clicked = Color::Red);



	// Odziedziczono za poœrednictwem elementu Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const override;

};

