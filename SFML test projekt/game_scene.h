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
#include "game_over_scene.h"
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

	Sprite hearts_sprite;
	Texture hearts_texture3;
	Texture hearts_texture2;
	Texture hearts_texture1;

	SoundBuffer crash_buff;
	Sound crash;

	vector<Food_fish*> foodies;
	Food_fish food;
	vector<Enemy*> enemies;


	//it is easier to create separate timers for every time dependant action and reset them every time action progs
	//otherwise it could maybe be done using if statements with % operation but it could potentially lead to program not working correctly
	int elapsed_time_movement;
	int elapsed_time_animation;
	float elapsed_time;
	float elapsed_time_adding_enemy;
	float collision_cooldown;

	float points;
	Text points_displayed;

	int hearts;

public:
	Game_scene(SceneManager* manager, RenderWindow* window);
	void update_point_text();
	void move_background();
	void add_enemy();
	bool check_collision_enemy(int i);
	bool check_collision_food(int i);

	// Odziedziczono za pośrednictwem elementu Scene
	virtual void handling_events(const sf::Event& event) override;
	virtual void render() override;
	virtual void update(const sf::Time& deltaTime) override;
};
