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
}


//if we wanted to set those parameters through a parametric constructor we'd have to make all buttons inside scene classes dynamically, so it is easier to create
//them with a defaut construcor and then initialize them using set_parameters() method
void Button::set_parameters(int x, int y, string mes, int pos_x, int pos_y)
{

	shape.setPosition(pos_x, pos_y);
	shape.setSize(Vector2<float> {(float)x, (float)y});
	shape.setOrigin((x / 2), -(y / 2));
	text.setString(mes);
	shape.setOutlineColor(brown);
	shape.setOutlineThickness(3);
	shape.setFillColor(vanilla);

	buff.loadFromFile("assets\\audio\\universfield.wav");
	click_sound.setBuffer(buff);
	font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	text.setFont(font);
	text.setFillColor(vanilla);
	text.setOutlineColor(brown);
	text.setOutlineThickness(2);
	text.setCharacterSize(72);
	shape.setOutlineColor(brown);
	shape.setOutlineThickness(3);
	shape.setFillColor(vanilla);

	const FloatRect bounds(text.getLocalBounds());
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
//the button should light up whenever mouse cursor is on it
void Button::mouse_on_highlight(Vector2i mouse_position)
{
	if (is_mouse_on(mouse_position))
	{
		shape.setFillColor(intense_vanilla);
	}

	else
	{
		shape.setFillColor(vanilla);
	}
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(shape, states);
	target.draw(text);
}


