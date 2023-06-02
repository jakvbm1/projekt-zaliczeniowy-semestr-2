#include "food.h"

Food_fish::Food_fish()
{
	this->texture_1.loadFromFile("assets\\graphics\\food_texture_1.png");
	this->texture_2.loadFromFile("assets\\graphics\\food_texture_2.png");
	this->food_sprite.setTexture(texture_1, true);
	this->food_sprite.setScale({ 4, 4 });
	this->animation_change = true;
	relocating();
}

void Food_fish::move()
{
	if (animation_change)
	{
		this->position -= {2, 2};
	}
	else
	{
		this->position -= {2, -2};
	}

	food_sprite.setPosition(position);
	
}


void Food_fish::change_texture()
{
	if (this->animation_change)
	{
		this->food_sprite.setTexture(texture_2);
		this->animation_change = false;
	}

	else
	{
		this->food_sprite.setTexture(texture_1);
		this->animation_change = true;
	}
}

void Food_fish::relocating()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist_horizontal(1, 800);
	std::uniform_int_distribution<std::mt19937::result_type> dist_vertical(1, 500);

	this->position.x = 800 + (float)dist_horizontal(rng);
	this->position.y = 150 + (float)dist_vertical(rng);
	this->food_sprite.setPosition(position);
}

void Food_fish::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(food_sprite, states);
}
