#include "button.h"

Button::Button()
{
}

Button::Button(float width, float height, float x, float y, string message, Color c_stand, Color c_mouse_on, Color c_clicked)
{
	color = c_stand;
	color_when_mouse_on = c_mouse_on;
	color_when_clicked = c_clicked;

	buff.loadFromFile("assets\\audio\\universfield.wav");
	click_sound.setBuffer(buff);

	shape.setPosition(x, y);
	shape.setSize(Vector2<float> {width, height});
	shape.setOrigin((width / 2),-(height / 2));
	shape.setOutlineColor(Color::Black);
	shape.setOutlineThickness(3);
	shape.setFillColor(color);

	font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	text.setFont(font);
	text.setString(message);
	text.setFillColor(Color::White);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(2);
	text.setCharacterSize(72);

	const  FloatRect bounds(text.getLocalBounds());
	const Vector2f box(shape.getSize());
	text.setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);
	text.setPosition(x- (width/2), y + (height/2));

}

void Button::pressed()
{
	shape.setFillColor(color_when_clicked);
	
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
	shape.setOutlineColor(Color::Black);
	shape.setOutlineThickness(3);
	shape.setFillColor(color);

	color = Color::White;
	color_when_mouse_on = Color::Yellow;
	color_when_clicked = Color::Red;

	buff.loadFromFile("assets\\audio\\universfield.wav");
	click_sound.setBuffer(buff);
	font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	text.setFont(font);
	text.setFillColor(Color::White);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(2);
	text.setCharacterSize(72);
	shape.setOutlineColor(Color::Black);
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


