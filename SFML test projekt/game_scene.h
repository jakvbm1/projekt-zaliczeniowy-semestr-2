#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "scene.h"
#include "SceneManager.h"
#include "menu.h"
#include "Enemy.h"
#include "Player.h"
#include "food.h"
#include "button.h"
#include <vector>
#include <iostream>


class Game_scene: public Scene
{
private:

	Text credits_text_1;
	Button back_button;
	Font font;
	Texture background_t;
	Sprite background;
	Player player;
	Music music;
	vector<Food_fish*> foodies;
	Food_fish food;
	vector<Enemy*> enemies;

	int elapsed_time_movement;
	int elapsed_time_animation;
	float elapsed_time;
	float elapsed_time_adding_enemy;

	float points;
	Text points_displayed;

	//tymczasowo
	RectangleShape fish_hitbox;

public:
	Game_scene(SceneManager* manager, RenderWindow* window);
	void update_point_text();
	void move_background();
	void add_enemy();
	bool check_collision_enemy(int i);
	bool check_collision_food(int i);

	// Odziedziczono za poœrednictwem elementu Scene
	virtual void handling_events(const sf::Event& event) override;
	virtual void render() override;
	virtual void update(const sf::Time& deltaTime) override;
};
