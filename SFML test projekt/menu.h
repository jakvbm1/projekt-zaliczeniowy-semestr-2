#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "button.h"
#include "scene.h"
#include "SceneManager.h"
#include "credits.h"
#include "Rules.h"
#include "game_scene.h"

using namespace std;
using namespace sf;

class Menu : public Scene
{
private:

	//variables used in menu
	Texture background_t;
	Sprite background;

	Texture logo_t;
	Sprite logo;

	Font main_font;

	Button start_button;
	Button exit_button;
	Button rules_button;
	Button credits_button;


	Text authors;


public:

	Menu(SceneManager* manager, RenderWindow* window);
	virtual ~Menu();
	virtual void handling_events(const sf::Event& event) override;
	virtual void update(const sf::Time& deltaTime) override;
	virtual void render() override;
};
