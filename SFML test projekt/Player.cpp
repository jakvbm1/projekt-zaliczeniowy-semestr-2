#include "Player.h"

Player::Player()
{
	this->texture.loadFromFile("assets\\graphics\\rybka.png");
	this->fish.setTexture(texture, true);
	this->position = { 50, 200 };
	this->fish.setPosition(position);
	this->fish.setScale({ 0.3, 0.3 });

	this->up = false;
	this->down = false;
}


void Player::player_movement(Keyboard::Key key, bool checkPressed)
{
	if (checkPressed == true)
	{
		if (key == Keyboard::Up)
		{
			this->down = false;
			this->up = true;
		}
		else if (key == Keyboard::Down)
		{
			this->up = false;
			this->down = true;
		}
	}
	if (checkPressed == false)
	{
		if (key == Keyboard::Up)
			this->up = false;
		else if (key == Keyboard::Down)
			this->down = false;
		else
		{
			this->up = false;
			this->down = false;
		}
	}
}

void Player::update()
{
	if(up)
		fish.move(0, -5.0f);
	if(down)
		fish.move(0, 5.0f);
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(fish, states);
}
