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

//this function changes the bool values for up/down player movement
//by information given from game_scene.cpp about pressed/released keyboard keys
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

//checks if player is in scene boundaries and changes its position by the given bool variables
void Player::update()
{
	if (up && position.y > 60.0f)
		position.y -= 3.5f;
	if(down && position.y < 680.0f)
		position.y += 3.5f;
	fish.setPosition(position);
}

//changes between two player's textures
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

//passes the modified sprite's rectangle parameters as its hitbox
FloatRect Player::pass_position()
{
	FloatRect hitbox;
	hitbox.height = fish.getGlobalBounds().height - 55;
	hitbox.width = fish.getGlobalBounds().width - 100;
	hitbox.left = fish.getGlobalBounds().left + 90;
	hitbox.top = fish.getGlobalBounds().top + 30;
	return hitbox;
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(fish, states);
}
