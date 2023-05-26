#include "menu.h"

void Menu::initialize_vars()
{
	this->start_button =new Button { 400, 100, 512, 184, "start game" };
	this->exit_button = new Button{ 400, 100, 512, 484 , "exit game" };
	this->rules_button = new Button{ 190, 100, 412, 334, "rules" };
	this->credits_button = new Button{ 190, 100, 622, 334, "credits" };

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
	delete this->start_button;
	delete this->exit_button;
	delete this->rules_button;
	delete this->credits_button;
}

void Menu::handling_events(const sf::Event& event)
{

		Vector2i mouse_position = Mouse::getPosition(*this->window);
        switch (event.type)
        {

        case Event::MouseButtonPressed:
        {
            
            if (abs(mouse_position.x - 512) < 200 && abs(mouse_position.y - 584) < 50)
            {
                exit_button->pressed();
				this->window->close();
            
            }

            else if (abs(mouse_position.x - 512) < 200 && abs(mouse_position.y - 284) < 50)
            {
                start_button->pressed();

            }

            else if (abs(mouse_position.x - 412) < 95 && abs(mouse_position.y - 434) < 50)
            {
                rules_button->pressed();

            }

            else if (abs(mouse_position.x - 622) < 95 && abs(mouse_position.y - 434) < 50)
            {
                credits_button->pressed();
				manager->set_scene(std::make_unique<Credits>(manager, window));
            }
            break;
        }

        }
	}

void Menu::update()
{
}

void Menu::render()
{
	//this->window->clear();
	this->window->draw(background);
	this->window->draw(title);
	this->window->draw(authors);
	this->window->draw(*start_button);
	this->window->draw(*rules_button);
	this->window->draw(*credits_button);
	this->window->draw(*exit_button);
}
