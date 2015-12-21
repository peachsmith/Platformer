/*
 * Scenery.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: jepye
 */

#include "Scenery.h"

namespace peach
{

Scenery::Scenery() :
		sprite_sheet(0), sheet_x(0), sheet_y(0)
{
	SetID(peach::SCENERY);
	Scenery::x = 0;
	Scenery::y = 0;
	Scenery::x_bound = 0;
	Scenery::y_bound = 0;
	x_scale = x_bound * 2;
	y_scale = y_bound * 2;
}

Scenery::Scenery(float x, float y, float x_bound, float y_bound, int sheet_x, int sheet_y, void* sprite_sheet)
{
	SetID(peach::SCENERY);
	Scenery::x = x;
	Scenery::y = y;
	Scenery::x_bound = x_bound;
	Scenery::y_bound = y_bound;
	Scenery::sheet_x = sheet_x;
	Scenery::sheet_y = sheet_y;
	Scenery::sprite_sheet = sprite_sheet;
	x_scale = x_bound * 2;
	y_scale = y_bound * 2;
}

Scenery::~Scenery()
{

}

void Scenery::Render()
{
	al_draw_bitmap_region((ALLEGRO_BITMAP*) sprite_sheet, sheet_x, sheet_y, x_bound, y_bound, x, y, 0);
	//al_draw_scaled_bitmap((ALLEGRO_BITMAP*) sprite_sheet, sheet_x, sheet_y, x_bound, y_bound, x, y, x_scale, y_scale, 0);
}

} /* namespace peach */
