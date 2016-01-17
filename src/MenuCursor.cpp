#include "MenuCursor.h"

namespace peach
{

MenuCursor::MenuCursor() :
		coordinates(0), row(0), column(0), rows(0), columns(0), menu_top(0)
{

}

MenuCursor::MenuCursor(int** coordinates) :
		row(0), column(0), rows(0), columns(0), menu_top(0)
{
	MenuCursor::coordinates = coordinates;
}

MenuCursor::MenuCursor(int** coordinates, int row, int column, int rows, int columns, int menu_top)
{
	MenuCursor::coordinates = coordinates;
	MenuCursor::row = row;
	MenuCursor::column = column;
	MenuCursor::rows = rows;
	MenuCursor::columns = columns;
	MenuCursor::menu_top = menu_top;
}

MenuCursor::~MenuCursor()
{

}

void MenuCursor::Render()
{
	al_draw_filled_triangle(coordinates[row][column], menu_top + row * 20, coordinates[row][column] + 10, menu_top + row * 20 + 5, coordinates[row][column], menu_top + row * 20 + 10, al_map_rgb(255, 255, 255));
}

void MenuCursor::Move(int direction)
{
	switch (direction)
	{
	case peach::UP:
		if (row > 0)
			row--;
		break;
	case peach::DOWN:
		if (row <= rows - 2)
		{
			if (coordinates[row + 1][column] != -1)
				row++;
		}
		break;
	case peach::LEFT:
		if (column > 0)
			column--;
		break;
	case peach::RIGHT:
		if (column <= columns - 2)
		{
			if (coordinates[row][column + 1] != -1)
				column++;
		}
		break;
	default:
		break;
	}
}

} /* namespace peach */
