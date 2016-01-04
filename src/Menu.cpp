/*
 * Menu.cpp
 *
 *  Created on: Jan 3, 2016
 *      Author: john
 */

#include "Menu.h"

namespace peach
{

Menu::Menu() :
		x(0), y(0), w(0), h(0)
{

}

Menu::Menu(int x, int y, int w, int h, std::vector<peach::MenuItem> menu_items)
{
	Menu::x = x;
	Menu::y = y;
	Menu::w = w;
	Menu::h = h;
	Menu::menu_items = menu_items;
}

Menu::~Menu()
{

}

void Menu::Render()
{
	al_draw_filled_rounded_rectangle(x, y, x + w, y + h, 5, 5, al_map_rgb_f(0, 0, 0));
	al_draw_rounded_rectangle(x + 5, y + 5, x + w - 5, y + h - 5, 5, 5, al_map_rgb(250, 250, 250), 3);
	if(menu_items.size() > 0)
	{
		for(int i = 0; i < menu_items.size(); i++)
		{
			menu_items[i].Render();
		}
	}
}

void Menu::Open()
{


}

void Menu::Close()
{

}

void Menu::Select()
{

}

void Menu::Back()
{

}

} /* namespace peach */
