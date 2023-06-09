#include "game_over_scene.h"

Game_over_scene::Game_over_scene(SceneManager* manager, RenderWindow* window) : Scene(manager, window)
{
	this->play_again_button.set_parameters(400, 100, "play again", 512, 184);
	this->menu_button.set_parameters(400, 100, "menu", 512, 484);
}

void Game_over_scene::handling_events(const sf::Event& event)
{
}

void Game_over_scene::render()
{
}

void Game_over_scene::update(const sf::Time& deltaTime)
{
}
