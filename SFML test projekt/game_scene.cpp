#include "game_scene.h"

Game_scene::Game_scene(SceneManager* manager, RenderWindow* window) : Scene(manager, window)
{
	this->background_t.loadFromFile("assets\\graphics\\placeholder_background.png");
	this->background.setTexture(background_t, true);
	this->elapsed_time_movement = 0;
	this->elapsed_time_animation = 0;
	this->elapsed_time = 0;
}

void Game_scene::handling_events(const sf::Event& event)
{
	if (event.type == Event::KeyPressed)
		player.player_movement(event.key.code, true);
	
	if (event.type == Event::KeyReleased)
		player.player_movement(event.key.code, false);
	
}

void Game_scene::render()
{
	this->window->draw(background);
	this->window->draw(enemy);
	this->window->draw(player);
}

void Game_scene::update(const sf::Time& deltaTime)
{
	player.update();
	this->elapsed_time_movement += deltaTime.asMilliseconds();
	this->elapsed_time_animation += deltaTime.asMilliseconds();
	this->elapsed_time += deltaTime.asSeconds();
	cout << elapsed_time << '\n';
	{
		if (elapsed_time_movement > 20)
		{
			this->enemy.moving(elapsed_time);
			elapsed_time_movement = 0;
		}

		if (elapsed_time_animation > 500)
		{
			this->enemy.change_texture();
			elapsed_time_animation = 0;
		}
	}

	
}