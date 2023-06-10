#include "game_over_scene.h"
#include<iostream>

Game_over_scene::Game_over_scene(int points, SceneManager* manager, RenderWindow* window) : Scene(manager, window)
{
	this->points = points;
	this->play_again_button.set_parameters(400, 100, "play again", 512, 284);
	this->menu_button.set_parameters(400, 100, "menu", 512, 484);

	this->background_t.loadFromFile("assets\\graphics\\background_texture.png");
	this->background.setTexture(background_t, true);
	this->background.setScale({ 4, 4 });

	this->font.loadFromFile("assets\\fonts\\dpcomic.ttf");

	this->upper_text.setFont(font);
	this->upper_text.setCharacterSize(60);
	this->upper_text.setFillColor(vanilla);
	this->upper_text.setOutlineColor(brown);
	this->upper_text.setOutlineThickness(2);
	this->upper_text.setString("GAME OVER");

	const FloatRect bounds_ut(upper_text.getLocalBounds());
	this->upper_text.setOrigin(bounds_ut.width / 2, bounds_ut.height / 2);
	this->upper_text.setPosition(512, 80);

	this->lower_text.setFont(font);
	this->lower_text.setCharacterSize(48);
	this->lower_text.setFillColor(vanilla);
	this->lower_text.setOutlineColor(brown);
	this->lower_text.setOutlineThickness(2);
	string points_s = "POINTS: " + to_string(points);
	this->lower_text.setString(points_s);

	const FloatRect bounds_lt(lower_text.getLocalBounds());
	this->lower_text.setOrigin(bounds_lt.width / 2, bounds_lt.height / 2);
	this->lower_text.setPosition(512, 150);




}

void Game_over_scene::handling_events(const sf::Event& event)
{
	Vector2i mouse_position = Mouse::getPosition(*this->window);

	if(event.type == Event::MouseMoved)
	{
		menu_button.mouse_on_highlight(mouse_position);
		play_again_button.mouse_on_highlight(mouse_position);
	}

	else if (event.type == Event::MouseButtonPressed)
	{

		if (menu_button.is_mouse_on(mouse_position))
		{
			menu_button.pressed();
			manager->set_scene(std::make_unique<Menu>(manager, window));

		}

		else if (play_again_button.is_mouse_on(mouse_position))
		{
			play_again_button.pressed();
			manager->set_scene(std::make_unique<Game_scene>(manager, window));
		}
	}
}

void Game_over_scene::render()
{
	this->window->draw(background);
	this->window->draw(upper_text);
	this->window->draw(lower_text);
	this->window->draw(play_again_button);
	this->window->draw(menu_button);
}

void Game_over_scene::update(const sf::Time& deltaTime)
{
}
