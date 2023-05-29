#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"button.h"
#include<math.h>
#include "scene.h"
#include"SceneManager.h"
#include"credits.h"
#include"Rules.h"
#include<SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Player : public Drawable
{
private:
	const int x;
	int y;
	Texture texture_n1;
	Texture texture_n2;
	Sprite fish_body;
	RectangleShape hit_box;

public:
	void move();
	// Odziedziczono za po�rednictwem elementu Drawable
	virtual void draw(RenderTarget& target, RenderStates states) = 0;
};

