#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"button.h"
#include<math.h>
#include "scene.h"
#include"SceneManager.h"
#include"menu.h"

using namespace std;
using namespace sf;

class Credits: public Scene
{
private:

	Text rules_text_1;
	Button back_button;
	Font font;
	RectangleShape rectangle;
public:
	Credits(SceneManager* manager, RenderWindow* window);

	// Odziedziczono za poœrednictwem elementu Scene
	virtual void handling_events(const sf::Event& event) override;
	virtual void render() override;
	virtual void update() override;

};
