#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "scene.h"
#include "SceneManager.h"
#include "menu.h"
#include "game_scene.h"
#include "button.h"
#include <iostream>

class Game_over_scene :public Scene
{
private:
	Button play_again_button;
	Button menu_button;
	int points;

	Font font;
	Text upper_text;
	Text lower_text;

	Texture background_t;
	Sprite background;

public:
	Game_over_scene(int points,SceneManager* manager, RenderWindow* window);
	virtual void handling_events(const sf::Event& event) override;
	virtual void render() override;
	virtual void update(const sf::Time& deltaTime) override;
};