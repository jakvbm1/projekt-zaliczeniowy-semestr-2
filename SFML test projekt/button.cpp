#include "button.h"

Color vanilla{ 0xEFEDC3ff };
Color intense_vanilla{ 0xeae7afff };
Color brown{ 0x6F5745ff };

Button::Button()
{
}



void Button::pressed()
{
	
	click_sound.setPlayingOffset(seconds(0.2));
	click_sound.play();
	//sleep(seconds(0.3));
	
	

}

void Button::set_parameters(int x, int y, string mes, int pos_x, int pos_y)
{

	shape.setPosition(pos_x, pos_y);
	shape.setSize(Vector2<float> {(float)x, (float)y});
	shape.setOrigin((x / 2), -(y / 2));
	text.setString(mes);
	shape.setOutlineColor(outline_color);
	shape.setOutlineThickness(3);
	shape.setFillColor(color);

	color = vanilla;
	color_when_mouse_on = intense_vanilla;
	outline_color = brown;

	buff.loadFromFile("assets\\audio\\universfield.wav");
	click_sound.setBuffer(buff);
	font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	text.setFont(font);
	text.setFillColor(color);
	text.setOutlineColor(outline_color);
	text.setOutlineThickness(2);
	text.setCharacterSize(72);
	shape.setOutlineColor(outline_color);
	shape.setOutlineThickness(3);
	shape.setFillColor(color);

	const  FloatRect bounds(text.getLocalBounds());
	const Vector2f box(shape.getSize());
	text.setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);
	text.setPosition(pos_x - (x / 2), pos_y + (y / 2));

}

bool Button::is_mouse_on(Vector2i mouse_position)
{
	if (abs(mouse_position.x - shape.getPosition().x) < (shape.getSize().x / 2) && abs(mouse_position.y - shape.getPosition().y - shape.getSize().y) < (shape.getSize().y / 2))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Button::mouse_on_highlight(Vector2i mouse_position)
{
	if (is_mouse_on(mouse_position))
	{
		shape.setFillColor(color_when_mouse_on);
	}

	else
	{
		shape.setFillColor(color);
	}
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(shape, states);
	target.draw(text);
}


