#include "Fish.h"

Fish::Fish(float width, float height, float x, float y)
{
	hit_box.setPosition(x, y);
	hit_box.setSize(Vector2<float> {width, height});
}

