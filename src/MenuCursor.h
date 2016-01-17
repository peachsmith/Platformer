#ifndef MENUCURSOR_H_
#define MENUCURSOR_H_

#include "peach_base.h"
#include "IDrawable.h"

namespace peach
{

class MenuCursor: public IDrawable
{
private:
	int** coordinates;
	int row;
	int column;
	int rows;
	int columns;
	int menu_top;
public:
	MenuCursor();
	MenuCursor(int** coordinates);
	MenuCursor(int** coordinates, int row, int column, int rows, int columns, int menu_top);
	void Render();
	virtual ~MenuCursor();
	void Move(int direction);

	void ResetPosition()
	{
		row = 0;
		column = 0;
	}

	int GetX()
	{
		return coordinates[row][column];
	}

	int GetY()
	{
		return menu_top + row * 20;
	}
};

} /* namespace peach */

#endif /* MENUCURSOR_H_ */
