#include "Rules.h"

Rules::Rules(SceneManager* manager, RenderWindow* window): Scene(manager, window)
{
	this->font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	this->rules_text_1.setFont(font);
	this->rules_text_1.setCharacterSize(60);
	this->rules_text_1.setString("Player movement (UP/DOWN)");
	this->rules_text_1.setOutlineColor(brown);
	this->rules_text_1.setFillColor(vanilla);
	this->rules_text_1.setOutlineThickness(3);
	this->rules_text_1.setPosition(350, 80);

	this->rules_text_2.setFont(font);
	this->rules_text_2.setCharacterSize(60);
	this->rules_text_2.setString("Watch out for sharks!");
	this->rules_text_2.setOutlineColor(brown);
	this->rules_text_2.setFillColor(vanilla);
	this->rules_text_2.setOutlineThickness(3);
	this->rules_text_2.setPosition(350, 250);

	this->rules_text_3.setFont(font);
	this->rules_text_3.setCharacterSize(60);
	this->rules_text_3.setString("Eat small fishes to get points");
	this->rules_text_3.setOutlineColor(brown);
	this->rules_text_3.setFillColor(vanilla);
	this->rules_text_3.setOutlineThickness(3);
	this->rules_text_3.setPosition(350, 400);

	this->back_button.set_parameters(400, 100, "Back to menu", 512, 484);
	this->background_t.loadFromFile("assets\\graphics\\background_texture.png");
	this->background.setTexture(background_t, true);
	this->background.setScale({ 4, 4 });

	this->k_arrows.loadFromFile("assets\\graphics\\keyboard_arrows.png");
	this->keyboard.setTexture(k_arrows, true);
	this->keyboard.setPosition(150, 100);
	this->keyboard.setScale(0.15, 0.15);
	const  FloatRect bounds_keyboard(keyboard.getLocalBounds());
	this->keyboard.setOrigin(bounds_keyboard.width / 2, bounds_keyboard.height / 2);

	this->shark_texture1.loadFromFile("assets\\graphics\\enemy_texture_1.png");
	this->shark_texture2.loadFromFile("assets\\graphics\\enemy_texture_2.png");
	this->shark.setTexture(shark_texture1, true);
	this->shark.setPosition(150, 290);
	this->shark.setScale(4, 4);
	const  FloatRect bounds_shark(shark.getLocalBounds());
	this->shark.setOrigin(bounds_shark.width / 2, bounds_shark.height / 2);

	this->food_texture1.loadFromFile("assets\\graphics\\food_texture_1.png");
	this->food_texture2.loadFromFile("assets\\graphics\\food_texture_2.png");
	this->food.setTexture(food_texture1, true);
	this->food.setPosition(150, 440);
	this->food.setScale(4, 4);
	const  FloatRect bounds_food(food.getLocalBounds());
	this->food.setOrigin(bounds_food.width / 2, bounds_food.height / 2);

	this->animation_change = true;
	this->elapsed_time_animation = 0;
}

void Rules::handling_events(const sf::Event& event)
{
	Vector2i mouse_position = Mouse::getPosition(*this->window);
	switch (event.type)
	{
	case Event::MouseMoved:
	{
		back_button.mouse_on_highlight(mouse_position);
		break;
	}

	case Event::MouseButtonPressed:
	{
		if (back_button.is_mouse_on(mouse_position))
		{
			back_button.pressed();
			manager->set_scene(std::make_unique<Menu>(manager, window));
		}
		break;
	}
	}
}

void Rules::render()
{
	window->draw(background);
	window->draw(rules_text_1);
	window->draw(rules_text_2);
	window->draw(rules_text_3);
	window->draw(back_button);
	window->draw(keyboard);
	window->draw(shark);
	window->draw(food);
}

//enemies and food animation in rules scene
void Rules::update(const sf::Time& deltaTime)
{
	this->elapsed_time_animation += deltaTime.asMilliseconds();

	if (elapsed_time_animation > 500)
	{
		if (this->animation_change)
		{
			shark.setTexture(shark_texture2);
			food.setTexture(food_texture2);
			this->animation_change = false;
		}

		else
		{
			shark.setTexture(shark_texture1);
			food.setTexture(food_texture1);
			this->animation_change = true;
		}

		elapsed_time_animation = 0;
	}
}