#include "menu.h"

void Menu::initialize_vars()
{
	this->start_button.set_parameters(400, 100, "start game", 512, 184);
	this->exit_button.set_parameters(400, 100, "exit game", 512, 484);
	this->rules_button.set_parameters(190, 100, "rules", 412, 334);
	this->credits_button.set_parameters(190, 100, "credits", 622, 334);


	this->main_font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	this->title.setFont(main_font);
	this->title.setCharacterSize(96);
	this->title.setString("RYBKI");
	this->title.setOutlineColor(Color::Black);
	this->title.setOutlineThickness(3);
	const  FloatRect bounds_title(title.getLocalBounds());
	this->title.setOrigin(bounds_title.width / 2, bounds_title.height / 2);
	this->title.setPosition(512, 100);


	this->authors.setFont(main_font);
	this->authors.setCharacterSize(48);
	this->authors.setString("Damian Knopek, Jakub Miarka");
	this->authors.setOutlineColor(Color::Black);
	this->authors.setOutlineThickness(2);
	const  FloatRect bounds_company(this->authors.getLocalBounds());
	this->authors.setOrigin(bounds_company.width / 2, bounds_company.height / 2);
	this->authors.setPosition(512, 668);

}


void Menu::initialize_background()
{
	
	this->background_t.loadFromFile("assets\\graphics\\placeholder_background.png");
	this->background.setTexture(background_t, true);
}


Menu::Menu(SceneManager* manager, RenderWindow* window):Scene(manager, window)
{
	initialize_vars();
	initialize_background();
}

Menu::~Menu()
{
}

void Menu::handling_events(const sf::Event& event)
{

		Vector2i mouse_position = Mouse::getPosition(*this->window);
        switch (event.type)
        {

		case Event::MouseMoved:
		{
			exit_button.mouse_on_highlight(mouse_position);
			start_button.mouse_on_highlight(mouse_position);
			credits_button.mouse_on_highlight(mouse_position);
			rules_button.mouse_on_highlight(mouse_position);
			break;
		}

        case Event::MouseButtonPressed:
        {
            
            if (exit_button.is_mouse_on(mouse_position))
            {
                exit_button.pressed();
				this->window->close();
            
            }

            else if (start_button.is_mouse_on(mouse_position))
            {
                start_button.pressed();

            }

            else if (rules_button.is_mouse_on(mouse_position))
            {
                rules_button.pressed();
				manager->set_scene(std::make_unique<Rules>(manager, window));

            }

            else if (credits_button.is_mouse_on(mouse_position))
            {
                credits_button.pressed();
				manager->set_scene(std::make_unique<Credits>(manager, window));
            }
            break;
        }

        }
	}

void Menu::update(const sf::Time& deltaTime)
{
}

void Menu::render()
{
	//this->window->clear();
	this->window->draw(background);
	this->window->draw(title);
	this->window->draw(authors);
	this->window->draw(start_button);
	this->window->draw(rules_button);
	this->window->draw(credits_button);
	this->window->draw(exit_button);
}
