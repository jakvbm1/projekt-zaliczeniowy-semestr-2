#include "game_scene.h"

Game_scene::Game_scene(SceneManager* manager, RenderWindow* window) : Scene(manager, window)
{
	this->background_t.loadFromFile("assets\\graphics\\placeholder_background.png");
	this->background.setTexture(background_t, true);
	this->elapsed_time = 0;
}

void Game_scene::handling_events(const sf::Event& event)
{
	switch (event.type)
	{
	case(Event::KeyPressed):
		switch (event.key.code)
		{
		case(Keyboard::Up):
		{
			this->player.changePosition(-10);
			break;
		}
		case(Keyboard::Down):
		{
			this->player.changePosition(10);
			break;
		}
		default:
			break;
		}
	default:
		break;
	}
}

void Game_scene::render()
{
	this->window->draw(background);
	this->window->draw(enemy);
	this->window->draw(player);
}

void Game_scene::update(const sf::Time& deltaTime)
{
	this->elapsed_time += deltaTime.asMilliseconds();
	{
		if (elapsed_time > 20)
		{
			this->enemy.moving();
			elapsed_time = 0;
		}
	}

	
}