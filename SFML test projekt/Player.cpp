#include "Player.h"

Player::Player()
{
	this->texture_1.loadFromFile("assets\\graphics\\player_texture_1.png");
	this->texture_2.loadFromFile("assets\\graphics\\player_texture_2.png");
	this->fish.setTexture(texture_1, true);
	this->position = { 75, 330 };
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

FloatRect Player::pass_position()
{
	FloatRect hitbox;
	hitbox.height = fish.getGlobalBounds().height - 55;
	hitbox.width = fish.getGlobalBounds().width - 100;
	hitbox.left = fish.getGlobalBounds().left + 90;
	hitbox.top = fish.getGlobalBounds().top + 30;
	return hitbox;
}

Vector2f Player::pass_hitbox_position()
{
	Vector2f hitbox_position;
	hitbox_position.x = fish.getGlobalBounds().left + 90;
	hitbox_position.y = fish.getGlobalBounds().top + 30;
	return hitbox_position;
}

Vector2f Player::pass_hitbox_size()
{
	Vector2f hitbox_size;
	hitbox_size.x = fish.getGlobalBounds().width - 100;
	hitbox_size.y = fish.getGlobalBounds().height - 55;
	return hitbox_size;
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(fish, states);
}
