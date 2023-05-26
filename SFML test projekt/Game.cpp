#include "Game.h"

Game::Game(string title): window(VideoMode(1024, 768), title)
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);
	manager.set_scene(std::make_unique<Menu>(&manager, &window));
}

void Game::play()
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			window.close();

			manager.handling_events(event);

		}
		window.clear();
		manager.update();
		manager.render();
		window.display();
	}
}

Game::~Game()
{
}
