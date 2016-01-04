#ifndef MENU_H_
#define MENU_H_

#include "peach_base.h"
#include "IDrawable.h"
#include "MenuItem.h"

namespace peach
{

class Menu: public IDrawable
{
private:
	int x;
	int y;
	int w;
	int h;
	std::vector<peach::MenuItem> menu_items;
public:
	Menu();
	Menu(int x, int y, int w, int h, std::vector<peach::MenuItem> menu_items);
	virtual ~Menu();

	void Render();

	void Open();
	void Close();
	void Select();
	void Back();

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

	std::vector<peach::MenuItem> GetMenuItems()
	{
		return menu_items;
	}

	void SetMenuItems(std::vector<peach::MenuItem> menu_items)
	{
		Menu::menu_items = menu_items;
	}

};

} /* namespace peach */

#endif /* MENU_H_ */
