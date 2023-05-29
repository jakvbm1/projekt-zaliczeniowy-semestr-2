#include "Player.h"

Player::Player()
{
	this->texture.loadFromFile("assets\\graphics\\rybka.png");
	this->fish.setTexture(texture, true);
	this->position = { 200, 200 };
	this->fish.setPosition(position);
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(fish, states);
}
