#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>;
#include "scene.h"
#include"SceneManager.h"
#include"game_scene.h"

class Enemy : public Drawable
{
private:
	Sprite enemy_sprite;
	Texture texture_1;
	Texture texture_2;




	// Odziedziczono za poœrednictwem elementu Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const override;
};