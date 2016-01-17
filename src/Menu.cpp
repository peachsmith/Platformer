#include "Menu.h"

namespace peach
{

Menu::Menu() :
		x(0), y(0), w(0), h(0), cursor(0), open(0)
{

}

Menu::Menu(float x, float y, int w, int h, std::vector<peach::MenuItem> items, peach::MenuCursor* cursor) :
		open(0)
{
	Menu::x = x;
	Menu::y = y;
	Menu::w = w;
	Menu::h = h;
	Menu::items = items;
	Menu::cursor = cursor;
}

Menu::~Menu()
{

}

void Menu::Render()
{
	if (open)
	{
		al_draw_filled_rounded_rectangle(x, y, x + w, y + h, 5, 5, al_map_rgb_f(0, 0, 0));
		al_draw_rounded_rectangle(x + 5, y + 5, x + w - 5, y + h - 5, 5, 5, al_map_rgb(250, 250, 250), 3);
		if (items.size() > 0)
		{
			for (unsigned int i = 0; i < items.size(); i++)
			{
				items[i].Render();
			}
		}
		cursor->Render();
	}
}

void Menu::Open()
{
	std::cout << "Menu::Open()" << std::endl;
	cursor->ResetPosition();
	if (open == 0)
		open = 1;
}

void Menu::Close()
{
	std::cout << "Menu::Close()" << std::endl;
	if (open == 1)
		open = 0;
}

int Menu::Select()
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i].GetX() - 15 == cursor->GetX() && items[i].GetY() + 5 == cursor->GetY())
			return items[i].GetItemID();
	}

	return -1;
}

void Menu::Back()
{
	std::cout << "Menu::Back()" << std::endl;
}

int Menu::HandleKeyboardInput(int keycode)
{
	int action = -1;

	switch (keycode)
	{
	case ALLEGRO_KEY_UP:
		cursor->Move(peach::UP);
		break;
	case ALLEGRO_KEY_DOWN:
		cursor->Move(peach::DOWN);
		break;
	case ALLEGRO_KEY_LEFT:
		cursor->Move(peach::LEFT);
		break;
	case ALLEGRO_KEY_RIGHT:
		cursor->Move(peach::RIGHT);
		break;
	case ALLEGRO_KEY_Z:
		action = Select();
		break;
	case ALLEGRO_KEY_X:
		Back();
		break;
	default:
		break;
	}

	return action;
}

} /* namespace peach */
