#include "Enemy.h"

Enemy::Enemy()
{
	this->texture_1.loadFromFile("assets\\graphics\\enemy_texture_1.png");
	this->texture_2.loadFromFile("assets\\graphics\\enemy_texture_2.png");
	this->enemy_sprite.setTexture(texture_1, true);
	this->enemy_sprite.setScale({ 4, 4 });
	relocating();

	this->animation_change = true;
}

void Enemy::relocating()
{
	//we decided that it will be better to have few prefixed values for height because when height was
	//made the same way width is, sharks tended to dont appear near upper boundary of the screen
	int heights[12] = { 25,75, 125,175, 225,275, 325,375, 425,475, 525,575 };

	std::random_device dev;
	std::mt19937 rng(dev());

	//horizontal position is altered randomly so the sharks differs in position so it looks more natural
	std::uniform_int_distribution<std::mt19937::result_type> dist_horizontal(1, 800);
	std::uniform_int_distribution<std::mt19937::result_type> vertical_index(1, 13);

	this->position.x = 800 + (float)dist_horizontal(rng);
	this->position.y = heights[vertical_index(rng) - 1];
	this->enemy_sprite.setPosition(position);
}

void Enemy::moving(float acceletarion)
{
	if (position.x < -200)
	{
		relocating();
	}

	//the acceleration is meant to be time which has passed, so sharks will be getting faster overtime
	float how_fast = acceletarion / 20;
	if (how_fast > 10)
	{
		how_fast = 10;
	}

	this->position -= {4 + how_fast, 0};
	this->enemy_sprite.setPosition(position);
}
//the idea for changing texture is really simple, whenever texture is changed, bool variable's value is also changed, so when the method is 
//called another time the texture is changed to the correct one, the same mechanism is used in Player and Food classes
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

//passes the modified enemy's rectangle parameters as its hitbox
FloatRect Enemy::pass_position()
{
	FloatRect hitbox;
	hitbox.height = enemy_sprite.getGlobalBounds().height - 70;
	hitbox.width = enemy_sprite.getGlobalBounds().width - 200;
	hitbox.left = enemy_sprite.getGlobalBounds().left + 15;
	hitbox.top = enemy_sprite.getGlobalBounds().top + 55;
	return hitbox;
}

void Enemy::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(enemy_sprite, states);
}
