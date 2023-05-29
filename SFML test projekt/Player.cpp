#include "Player.h"

Player::Player()
{
	this->texture.loadFromFile("assets\\graphics\\rybka.png");
	this->fish.setTexture(texture, true);
	this->position = { 200, 200 };
	this->fish.setPosition(position);
	this->up = false;
	this->down = false;
}

void Player::changePosition(float y)
{
	this->position += { 0, y };
	this->fish.setPosition(position);
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(fish, states);
}
