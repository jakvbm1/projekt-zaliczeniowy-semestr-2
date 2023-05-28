#include "game_scene.h"

Game_scene::Game_scene(SceneManager* manager, RenderWindow* window) : Scene(manager, window)
{
	this->background_t.loadFromFile("assets\\graphics\\placeholder_background.png");
	this->background.setTexture(background_t, true);
}

void Game_scene::handling_events(const sf::Event& event)
{

}

void Game_scene::render()
{
	this->window->draw(background);
}

void Game_scene::update(const sf::Time& deltaTime)
{
}