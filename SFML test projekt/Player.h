#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Player : public Drawable
{
private:
	Texture texture;
	Sprite fish;
	Vector2f position;

	bool up;
	bool down;

public:
	Player();
	void player_movement(Keyboard::Key key, bool checkPressed);
	void update();

	// Odziedziczono za poœrednictwem elementu Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const override;
};

