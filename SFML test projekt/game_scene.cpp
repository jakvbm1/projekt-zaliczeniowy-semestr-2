#include "game_scene.h"

Game_scene::Game_scene(SceneManager* manager, RenderWindow* window) : Scene(manager, window)
{
	this->background_t.loadFromFile("assets\\graphics\\game_background.png");
	this->background.setTexture(background_t);
	this->background.setScale(4, 4);

	this->elapsed_time_movement = 0;
	this->elapsed_time_animation = 0;
	this->elapsed_time = 0;
	this->elapsed_time_adding_enemy = 0;
	this->points = 0;

	this->music.openFromFile("assets\\audio\\game_music.wav");
	this->music.setLoop(true);
	this->music.setVolume(50);
	this->music.play();

	this->font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	this->points_displayed.setFont(font);
	this->points_displayed.setFillColor(vanilla);
	this->points_displayed.setOutlineColor(brown);
	this->points_displayed.setOutlineThickness(3);
	this->points_displayed.setCharacterSize(48);
	update_point_text();


	for (int i = 0; i < 3; i++)
	{
		this->enemies.push_back(new Enemy());
	}

	for (int i = 0; i < 4; i++)
	{
		this->foodies.push_back(new Food_fish());
	}

	this->hearts_texture3.loadFromFile("assets\\graphics\\three_hearts.png");
	this->hearts_texture2.loadFromFile("assets\\graphics\\two_hearts.png");
	this->hearts_texture1.loadFromFile("assets\\graphics\\one_heart.png");
	this->hearts_sprite.setScale({ 3.0, 3.0 });
	this->hearts_sprite.setPosition({ 20.0, 20.0 });
	this->hearts_sprite.setTexture(hearts_texture3, true);

	this->hearts = 3;
}

void Game_scene::update_point_text()
{
	string points_s = "Points: " + to_string((int)points);
	this->points_displayed.setString(points_s);
	
	const  FloatRect bounds_title(points_displayed.getLocalBounds());
	this->points_displayed.setOrigin(bounds_title.width / 2, bounds_title.height / 2);
	this->points_displayed.setPosition(512, 30);

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
		position += {-2, 0};
		background.setPosition(position);
	}
}

void Game_scene::add_enemy()
{
	if (enemies.size() < 7)
	{
		enemies.push_back(new Enemy());
	}
}

bool Game_scene::check_collision_enemy(int i)
{
	if (player.pass_position().intersects(enemies[i]->pass_position()))
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Game_scene::check_collision_food(int i)
{
	if (player.pass_position().intersects(foodies[i]->pass_position()))
	{
		return true;
	}

	else
	{
		return false;
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
	this->window->draw(hearts_sprite);

	for (int i = 0; i < foodies.size(); i++)
	{
		this->window->draw(*foodies[i]);
	}

	this->window->draw(player);

	for (int i = 0; i < enemies.size(); i++)
	{
		this->window->draw(*enemies[i]);
	}

	this->window->draw(points_displayed);
}

void Game_scene::update(const sf::Time& deltaTime)
{
	player.update();

	this->elapsed_time_movement += deltaTime.asMilliseconds();
	this->elapsed_time_animation += deltaTime.asMilliseconds();
	this->elapsed_time += deltaTime.asSeconds();
	this->elapsed_time_adding_enemy += deltaTime.asSeconds();
	this->points += deltaTime.asSeconds() * 0.5;
	this->collision_cooldown += deltaTime.asSeconds();
	
	if (elapsed_time_movement > 20)
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			this->enemies[i]->moving(elapsed_time);
		}

		for (int i = 0; i < foodies.size(); i++)
		{
			this->foodies[i]->moving();
		}
		this->move_background();
		elapsed_time_movement = 0;
	}

	if (elapsed_time_animation > 500)
	{
		this->player.change_texture();
		for (int i = 0; i < foodies.size(); i++)
		{
			this->foodies[i]->change_texture();
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			this->enemies[i]->change_texture();
		}
			
		elapsed_time_animation = 0;
	}

	if (elapsed_time_adding_enemy > 50)
	{
		add_enemy();
		elapsed_time_adding_enemy = 0;
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		if (check_collision_enemy(i) && collision_cooldown > 3)
		{
			this->hearts -= 1;

			if (hearts == 2)
				this->hearts_sprite.setTexture(hearts_texture2, true);
			else if (hearts == 1)
				this->hearts_sprite.setTexture(hearts_texture1, true);

			this->collision_cooldown = 0;
		}
	}


	for (int i = 0; i < foodies.size(); i++)
	{
		if (check_collision_food(i))
		{
			this->foodies[i]->relocating();
			this->points += 20;
		}
	}

	update_point_text();

	if (hearts < 1)
	{
		enemies.clear();
		foodies.clear();
		music.stop();

		manager->set_scene(std::make_unique<Game_over_scene>((int)points, manager, window));
	}
}