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
			this->up = true;
		}
		if (key == Keyboard::Down)
		{
			this->down = true;
		}
	}
	if (checkPressed == false)
	{
		this->up = false;
		this->down = false;
	}
}

void Player::update()
{
	Vector2f movement;
	if(up)
		movement.y -= 5.0f;
	if(down)
		movement.y += 5.0f;
	fish.move(movement);
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(fish, states);
}
