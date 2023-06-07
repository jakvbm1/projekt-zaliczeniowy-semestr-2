#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<random>

using namespace sf;

class Enemy : public Drawable
{
private:
	Sprite enemy_sprite;
	Texture texture_1;
	Texture texture_2;
	//SoundBuffer sound_buff;
	//Sound eating_sound;
	Vector2f position;
	bool animation_change;

public:

	// Odziedziczono za poœrednictwem elementu Drawable
	Enemy();
	void relocating();
	void moving(float acceletarion);
	void change_texture();
	FloatRect pass_position();
	virtual void draw(RenderTarget& target, RenderStates states) const override;
};