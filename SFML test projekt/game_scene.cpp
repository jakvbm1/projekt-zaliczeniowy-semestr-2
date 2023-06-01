#include "game_scene.h"

Game_scene::Game_scene(SceneManager* manager, RenderWindow* window) : Scene(manager, window)
{
	this->background_t.loadFromFile("assets\\graphics\\game_background.png");
	this->background.setTexture(background_t);
	this->background.setScale(4, 4);
	this->elapsed_time_movement = 0;
	this->elapsed_time_animation = 0;
	this->elapsed_time = 0;
	this->music.openFromFile("assets\\audio\\game_music.wav");
	this->music.setLoop(true);
	this->music.setVolume(50);
	this->music.play();
}

void Game_scene::move_background()
{
	Vector2f position = background.getPosition();

	if (position.x == -3072)
	{
		background.setPosition({ 0, 0 });
	}
	else
	{
		position += {-1, 0};
		cout << "GOWNO : " << position.x << '\n';
		background.setPosition(position);
	}
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
	this->window->draw(food);
	this->window->draw(player);

	for (int i = 0; i < 3; i++)
	{
		this->window->draw(enemy[i]);
	}
}

void Game_scene::update(const sf::Time& deltaTime)
{
	player.update();
	this->elapsed_time_movement += deltaTime.asMilliseconds();
	this->elapsed_time_animation += deltaTime.asMilliseconds();
	this->elapsed_time += deltaTime.asSeconds();
	{
		if (elapsed_time_movement > 20)
		{
			for (int i = 0; i < 3; i++)
			{
				this->enemy[i].moving(elapsed_time);
			}
			this->food.move();
			this->move_background();
			elapsed_time_movement = 0;
		}

		if (elapsed_time_animation > 500)
		{
			this->food.change_texture();
			for (int i = 0; i < 3; i++)
			{
				this->enemy[i].change_texture();
			}
			
			elapsed_time_animation = 0;
		}
	}

	
}