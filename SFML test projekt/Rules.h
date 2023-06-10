#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "button.h"
#include "scene.h"
#include "SceneManager.h"
#include "menu.h"

class Rules : public Scene
{
private:
	Font font;
	Button back_button;
	Text rules_text_1;
	Text rules_text_2;
	Text rules_text_3;
	Texture background_t;
	Sprite background;
	Sprite keyboard;
	Texture k_arrows;
	Texture shark_texture1;
	Texture shark_texture2;
	Sprite shark;
	Texture food_texture1;
	Texture food_texture2;
	Sprite food;

	int elapsed_time_animation;
	bool animation_change;

public:
	Rules(SceneManager* manager, RenderWindow* window);
	// Odziedziczono za poœrednictwem elementu Scene
	virtual void handling_events(const sf::Event& event) override;
	virtual void render() override;
	virtual void update(const sf::Time& deltaTime) override;
};

