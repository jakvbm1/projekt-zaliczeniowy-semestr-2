#include "Player.h"

Player::Player()
{
	this->texture_1.loadFromFile("assets\\graphics\\player_texture_1.png");
	this->texture_2.loadFromFile("assets\\graphics\\player_texture_2.png");
	this->fish.setTexture(texture_1, true);
	this->position = { 20, 330 };
	this->fish.setPosition(position);
	this->fish.setScale({ 4, 4 });

	this->up = false;
	this->down = false;
	this->animation_change = true;
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
	if (up && position.y > -20.0f)
		position.y -= 5.0f;
	if(down && position.y < 680.0f)
		position.y += 5.0f;
	fish.setPosition(position);
}

void Player::change_texture()
{
	if (animation_change)
	{
		fish.setTexture(texture_2);
		animation_change = false;
	}

	else
	{
		fish.setTexture(texture_1);
		animation_change = true;
	}
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(fish, states);
}
