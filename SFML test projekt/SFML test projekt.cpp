
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"button.h"
#include<math.h>

using namespace sf;
using namespace std;

int main()
{
    Texture background;
    background.loadFromFile("assets\\graphics\\placeholder_background.png");
    Sprite background_s(background);

    Font main_font;
    main_font.loadFromFile("assets\\fonts\\dpcomic.ttf");


    Button start_button{ 400, 100, 512, 184, "start game"};
    Button rules_button{ 190, 100, 412, 334, "rules"};
   Button credits_button{ 190, 100, 622, 334, "credits"};
    Button exit_button{ 400, 100, 512, 484 , "exit game"};

    Text title;
    title.setFont(main_font);
    title.setCharacterSize(96);
    title.setString("game");
    title.setOutlineColor(Color::Black);
    title.setOutlineThickness(3);
    const  FloatRect bounds_title(title.getLocalBounds());
    title.setOrigin(bounds_title.width / 2, bounds_title.height / 2);
    title.setPosition(512, 100);

    Text company;
    company.setFont(main_font);
    company.setCharacterSize(48);
    company.setString("szniob de la dziob productions");
    company.setOutlineColor(Color::Black);
    company.setOutlineThickness(2);
    const  FloatRect bounds_company(company.getLocalBounds());
    company.setOrigin(bounds_company.width / 2, bounds_company.height / 2);
    company.setPosition(512, 668);


    RenderWindow window{ VideoMode{1024, 768}, "GRA TESTOWA" };
    window.setFramerateLimit(60);
    Event event;
    while (true)
    {
        window.clear(Color::Cyan);
        window.draw(background_s);
        window.draw(title);
        window.draw(company);
        window.draw(start_button);
        window.draw(rules_button);
      window.draw(credits_button);
        window.draw(exit_button);
        
        window.pollEvent(event);
        Vector2i position = Mouse::getPosition(window);
        switch (event.type)
        {
        case Event::Closed:
        {
            window.close();
            break;
        }

        case Event:: MouseButtonPressed:
        {
            cout << position.x << " " << position.y << endl;
            if (abs(position.x - 512) < 200 && abs(position.y - 584) < 50)
            {
                window.close();
                break;
            }

        }

        }


        //tu powinno byc zaktualizowanie stanu obiektow i wyswietlenie ich etc
        window.display();
    }
}

