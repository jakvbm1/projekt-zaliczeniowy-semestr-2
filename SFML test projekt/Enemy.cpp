#include "Enemy.h"

Enemy::Enemy()
{
	this->texture_1.loadFromFile("assets\\graphics\\enemy_texture_1.png");
	this->texture_2.loadFromFile("assets\\graphics\\enemy_texture_2.png");
	this->enemy_sprite.setTexture(texture_1, true);
	this->position = { 800, 200 };
	this->enemy_sprite.setPosition(position);
	this->animation_change = true;
}

void Enemy::moving(int acceletarion)
{

		this->position -= {3, 0};
		this->enemy_sprite.setPosition(position);

}

void Enemy::change_texture()
{
	if (this->animation_change)
	{
		enemy_sprite.setTexture(texture_2);
		this->animation_change = false;
	}

	else
	{
		enemy_sprite.setTexture(texture_1);
		this->animation_change = true;
	}

}

void Enemy::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(enemy_sprite, states);
}
