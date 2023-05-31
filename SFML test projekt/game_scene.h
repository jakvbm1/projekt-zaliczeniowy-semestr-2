#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "scene.h"
#include "SceneManager.h"
#include "menu.h"
#include "Enemy.h"
#include "Player.h"
#include "food.h"
#include <iostream>


class Game_scene: public Scene
{
private:

	Text credits_text_1;
	Button back_button;
	Font font;
	Texture background_t;
	Sprite background;
	Enemy enemy[3];
	Player player;
	Music music;
	Food_fish food;

	int elapsed_time_movement;
	int elapsed_time_animation;
	float elapsed_time;
public:
	Game_scene(SceneManager* manager, RenderWindow* window);

	// Odziedziczono za poœrednictwem elementu Scene
	virtual void handling_events(const sf::Event& event) override;
	virtual void render() override;
	virtual void update(const sf::Time& deltaTime) override;
};
