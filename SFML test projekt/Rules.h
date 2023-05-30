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
	Texture background_t;
	Sprite background;

public:
	Rules(SceneManager* manager, RenderWindow* window);
	// Odziedziczono za poœrednictwem elementu Scene
	virtual void handling_events(const sf::Event& event) override;
	virtual void render() override;
	virtual void update(const sf::Time& deltaTime) override;
};

