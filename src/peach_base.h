#ifndef PEACH_BASE_H_
#define PEACH_BASE_H_

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace peach
{

enum ID
{
	PLAYER, ENEMY, PROJECTILE, TERRAIN, SCENERY, GOAL
};
enum keys
{
	UP, DOWN, LEFT, RIGHT, A, Z, X, SPACE, ENTER
};
enum state
{
	START, PLAY, LEVEL_1, LEVEL_2, END
};

enum menu_item_id
{
	PAUSE_MENU_RESUME, PAUSE_MENU_QUIT, PAUSE_MENU_INFO
};

}

#endif
