#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>

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


public:
	// Odziedziczono za poœrednictwem elementu Drawable
	Enemy();
	void set_default_parameters();
	void moving();
	virtual void draw(RenderTarget& target, RenderStates states) const override;

};