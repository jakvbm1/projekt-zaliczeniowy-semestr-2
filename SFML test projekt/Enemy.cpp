#include "Enemy.h"

Enemy::Enemy()
{



	this->texture_1.loadFromFile("assets\\graphics\\enemy_texture_1.png");
	this->texture_2.loadFromFile("assets\\graphics\\enemy_texture_2.png");
	this->enemy_sprite.setTexture(texture_1, true);
	//this->position.x = 800;
	//this->position.y = 200;
	relocating();
	//this->enemy_sprite.setPosition(position);
	this->animation_change = true;
}

void Enemy::relocating()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist_horizontal(1, 200);
	std::uniform_int_distribution<std::mt19937::result_type> dist_vertical(1, 400);

	this->position.x = 800 + (float)dist_horizontal(rng);
	this->position.y = 200 + (float)dist_vertical(rng);
	this->enemy_sprite.setPosition(position);
}

void Enemy::moving(float acceletarion)
{

	if (position.x < -200)
	{
		relocating();
	}

	float how_fast = acceletarion / 10;
	if (how_fast > 10)
	{
		how_fast = 10;
	}



		this->position -= {3 + how_fast, 0};
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
