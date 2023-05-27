#include "credits.h"

Credits::Credits(SceneManager* manager, RenderWindow* window): Scene(manager, window)
{

	this->font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	this->credits_text_1.setFont(font);
	this->credits_text_1.setCharacterSize(60);
	this->credits_text_1.setString("there are gonna be credits (probably)");
	this->credits_text_1.setOutlineColor(Color::Black);
	this->credits_text_1.setOutlineThickness(3);
	const  FloatRect bounds_title(credits_text_1.getLocalBounds());
	this->credits_text_1.setOrigin(bounds_title.width / 2, bounds_title.height / 2);
	this->credits_text_1.setPosition(512, 100);

	this->back_button.set_parameters(400, 100, "Back to menu", 512, 484);
	this->background_t.loadFromFile("assets\\graphics\\placeholder_background.png");
	this->background.setTexture(background_t, true);
}

void Credits::handling_events(const sf::Event& event)
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

void Credits::render()
{
	this->window->draw(background);
	this->window->draw(credits_text_1);
	this->window->draw(back_button);

}

void Credits::update(const sf::Time& deltaTime)
{
}
