#ifndef MENU_H_
#define MENU_H_

#include "peach_base.h"
#include "IDrawable.h"
#include "MenuItem.h"
#include "MenuCursor.h"

namespace peach
{

class Menu: public IDrawable
{
private:
	float x;
	float y;
	int w;
	int h;
	std::vector<peach::MenuItem> items;
	peach::MenuCursor* cursor;
	int open;
public:
	Menu();
	Menu(float x, float y, int w, int h, std::vector<peach::MenuItem> menu_items, peach::MenuCursor* cursor);
	virtual ~Menu();

	void Render();

	void Open();
	void Close();
	int Select();
	void Back();
	int HandleKeyboardInput(int keycode);

	int GetX()
	{
		return x;
	}

	void SetX(int x)
	{
		Menu::x = x;
	}

	int GetY()
	{
		return y;
	}

	void SetY(int y)
	{
		Menu::y = y;
	}

	int GetW()
	{
		return w;
	}

	void Setw(int w)
	{
		Menu::w = w;
	}

	int GetH()
	{
		return h;
	}

	void SetH(int h)
	{
		Menu::h = h;
	}

	std::vector<peach::MenuItem> GetItems()
	{
		return items;
	}

	void SetItems(std::vector<peach::MenuItem> items)
	{
		Menu::items = items;
	}

};

} /* namespace peach */

#endif /* MENU_H_ */
