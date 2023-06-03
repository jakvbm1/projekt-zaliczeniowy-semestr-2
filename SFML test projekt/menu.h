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
	Font main_font;
	Button start_button;
	Button exit_button;
	Button rules_button;
	Button credits_button;
	Text title;
	Text authors;

	void initialize_vars();
	void initialize_background();

public:

	Menu(SceneManager* manager, RenderWindow* window);
	virtual ~Menu();
	virtual void handling_events(const sf::Event& event) override;
	virtual void update(const sf::Time& deltaTime) override;
	virtual void render() override;
};
