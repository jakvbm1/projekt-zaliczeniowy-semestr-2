#include "credits.h"

Credits::Credits(SceneManager* manager, RenderWindow* window): Scene(manager, window)
{

	this->font.loadFromFile("assets\\fonts\\dpcomic.ttf");
	//setting fonts for all Text objects
	this->programmers_headline.setFont(font);
	this->programmers.setFont(font);
	this->audio_headline.setFont(font);
	this->audio.setFont(font);
	this->idea_headline.setFont(font);
	this->idea.setFont(font);
	this->design_headline.setFont(font);
	this->design.setFont(font);

	//setting colors, outline and sizes of text objects

	this->programmers_headline.setFillColor(vanilla);
	this->programmers_headline.setOutlineColor(brown);
	this->programmers_headline.setOutlineThickness(3);
	this->programmers_headline.setCharacterSize(48);

	this->audio_headline.setFillColor(vanilla);
	this->audio_headline.setOutlineColor(brown);
	this->audio_headline.setOutlineThickness(3);
	this->audio_headline.setCharacterSize(48);

	this->idea_headline.setFillColor(vanilla);
	this->idea_headline.setOutlineColor(brown);
	this->idea_headline.setOutlineThickness(3);
	this->idea_headline.setCharacterSize(48);

	this->design_headline.setFillColor(vanilla);
	this->design_headline.setOutlineColor(brown);
	this->design_headline.setOutlineThickness(3);
	this->design_headline.setCharacterSize(48);

	this->programmers.setFillColor(vanilla);
	this->programmers.setOutlineColor(brown);
	this->programmers.setOutlineThickness(2);
	this->programmers.setCharacterSize(30);

	this->audio.setFillColor(vanilla);
	this->audio.setOutlineColor(brown);
	this->audio.setOutlineThickness(2);
	this->audio.setCharacterSize(30);

	this->idea.setFillColor(vanilla);
	this->idea.setOutlineColor(brown);
	this->idea.setOutlineThickness(2);
	this->idea.setCharacterSize(30);

	this->design.setFillColor(vanilla);
	this->design.setOutlineColor(brown);
	this->design.setOutlineThickness(2);
	this->design.setCharacterSize(30);

	//setting strings for all Text obj
	this->programmers_headline.setString("Programming:");
	this->programmers.setString("Damian Knopek, Jakub Miarka");

	this->idea_headline.setString("Original Concept:");
	this->idea.setString("Concept2");

	this->design_headline.setString("Characters/level design:");
	this->design.setString("Jakub Miarka, Damian Knopek");

	this->audio_headline.setString("Music, sound effects:");
	this->audio.setString("Jakub Miarka");

	//setting origin and position for all Texts

	const  FloatRect bounds(programmers_headline.getLocalBounds());
	this->programmers_headline.setOrigin(bounds.width / 2, bounds.height / 2);
	this->programmers_headline.setPosition(512, 60);

	const  FloatRect bounds_p(programmers.getLocalBounds());
	this->programmers.setOrigin(bounds_p.width / 2, bounds_p.height / 2);
	this->programmers.setPosition(512, 120);

	const  FloatRect bounds_ih(idea_headline.getLocalBounds());
	this->idea_headline.setOrigin(bounds_ih.width / 2, bounds_ih.height / 2);
	this->idea_headline.setPosition(512, 180);

	const  FloatRect bounds_i(idea.getLocalBounds());
	this->idea.setOrigin(bounds_i.width / 2, bounds_i.height / 2);
	this->idea.setPosition(512, 240);

	const  FloatRect bounds_dh(design_headline.getLocalBounds());
	this->design_headline.setOrigin(bounds_dh.width / 2, bounds_dh.height / 2);
	this->design_headline.setPosition(512, 300);

	const  FloatRect bounds_d(design.getLocalBounds());
	this->design.setOrigin(bounds_d.width / 2, bounds_d.height / 2);
	this->design.setPosition(512, 360);

	const  FloatRect bounds_ah(audio_headline.getLocalBounds());
	this->audio_headline.setOrigin(bounds_ah.width / 2, bounds_ah.height / 2);
	this->audio_headline.setPosition(512, 420);

	const  FloatRect bounds_a(audio.getLocalBounds());
	this->audio.setOrigin(bounds_a.width / 2, bounds_a.height / 2);
	this->audio.setPosition(512, 480);



	this->back_button.set_parameters(400, 100, "Back to menu", 512, 584);
	this->background_t.loadFromFile("assets\\graphics\\background_texture.png");
	this->background.setTexture(background_t, true);
	this->background.setScale({ 4, 4 });
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
	this->window->draw(programmers_headline);
	this->window->draw(programmers);
	this->window->draw(idea_headline);
	this->window->draw(idea);
	this->window->draw(design_headline);
	this->window->draw(design);
	this->window->draw(audio_headline);
	this->window->draw(audio);

	this->window->draw(back_button);

}

void Credits::update(const sf::Time& deltaTime)
{
}
