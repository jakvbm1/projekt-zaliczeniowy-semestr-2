#include "credits.h"

Credits::Credits(SceneManager* manager, RenderWindow* window): Scene(manager, window)
{
	this->rectangle.setFillColor(Color::Yellow);
	this->rectangle.setSize(Vector2f(1024, 768));

	this->font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	this->rules_text_1.setFont(font);
	this->rules_text_1.setCharacterSize(60);
	this->rules_text_1.setString("there are gonna be credits (probably)");
	this->rules_text_1.setOutlineColor(Color::Black);
	this->rules_text_1.setOutlineThickness(3);
	const  FloatRect bounds_title(rules_text_1.getLocalBounds());
	this->rules_text_1.setOrigin(bounds_title.width / 2, bounds_title.height / 2);
	this->rules_text_1.setPosition(512, 100);

	this->back_button.set_parameters(400, 100, "Back to menu", 512, 484);
}

void Credits::handling_events(const sf::Event& event)
{
	Vector2i mouse_position = Mouse::getPosition(*this->window);
	switch (event.type)
	{
		
	case Event::MouseButtonPressed:
		{
			if ((abs(mouse_position.x - 512) < 200 && abs(mouse_position.y - 584) < 50))
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
	this->window->draw(rectangle);
	this->window->draw(rules_text_1);
	this->window->draw(back_button);

}

void Credits::update()
{
}
