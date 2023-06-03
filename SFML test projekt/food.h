#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<random>

using namespace sf;

class Food_fish : public Drawable
{
private:
	Texture texture_1;
	Texture texture_2;
	Sprite food_sprite;
	Vector2f position;
	bool animation_change;

public:
	Food_fish();
	void moving();
	void change_texture();
	void relocating();
	// Odziedziczono za poœrednictwem elementu Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const override;

};
