#ifndef PEACH_BASE_H_
#define PEACH_BASE_H_

#include <iostream>
#include <list>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace peach
{

enum ID
{
	PLAYER, ENEMY, PROJECTILE, TERRAIN
};
enum keys
{
	UP, DOWN, LEFT, RIGHT, A, Z, X, SPACE
};

}

#endif
