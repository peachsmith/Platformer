/*
 * MenuItem.cpp
 *
 *  Created on: Jan 3, 2016
 *      Author: john
 */

#include "MenuItem.h"

namespace peach
{

MenuItem::MenuItem() :
		text(""), x(0), y(0), font(0)
{

}

MenuItem::MenuItem(std::string text, int x, int y, void* font)
{
	MenuItem::text = text;
	MenuItem::x = x;
	MenuItem::y = y;
	MenuItem::font = font;
}

MenuItem::~MenuItem()
{

}

void MenuItem::Render()
{
	al_draw_text((ALLEGRO_FONT*) font, al_map_rgb(250, 250, 250), x, y, 0, text.c_str());
}

} /* namespace peach */
