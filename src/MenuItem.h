#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "peach_base.h"
#include "IDrawable.h"

namespace peach
{

class MenuItem: public IDrawable
{
private:
	std::string text;
	int x;
	int y;
	void* font;
public:
	MenuItem();
	MenuItem(std::string text, int x, int y, void* font);
	virtual ~MenuItem();

	void Render();

	std::string GetText()
	{
		return text;
	}

	void SetText(std::string text)
	{
		MenuItem::text = text;
	}

	int GetX()
	{
		return x;
	}

	void SetX(int x)
	{
		MenuItem::x = x;
	}

	int GetY()
	{
		return y;
	}

	void SetY(int y)
	{
		MenuItem::y = y;
	}

	void* GetFont()
	{
		return font;
	}

	void SetFont(void* font)
	{
		MenuItem::font = font;
	}
};

} /* namespace peach */

#endif /* MENUITEM_H_ */
