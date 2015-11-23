/*
 * Terrain.cpp
 *
 *  Created on: Oct 4, 2015
 *      Author: jepye
 */

#include "Terrain.h"

namespace peach
{

Terrain::Terrain()
{

}

Terrain::Terrain(bool alive, bool collidable, float x, float y, float x_vel, float y_vel, float x_dir, float y_dir, float x_bound, float y_bound)
{
	SetID(peach::TERRAIN);
	SetAlive(alive);
	SetCollidable(collidable);

	Terrain::x = x;
	Terrain::y = y;
	Terrain::x_vel = x_vel;
	Terrain::y_vel = y_vel;
	Terrain::x_dir = x_dir;
	Terrain::y_dir = y_dir;
	Terrain::x_bound = x_bound;
	Terrain::y_bound = y_bound;
}

void Terrain::Render()
{
	al_draw_filled_rectangle(x, y, x + x_bound, y + y_bound, al_map_rgb(180, 180, 170));
	al_draw_rectangle(x, y, x + x_bound, y + y_bound, al_map_rgb(0, 0, 0), 1);
}

void Terrain::Collide(int object_id)
{
//TODO make stuff happen
}

void Terrain::UpdateX()
{

}

void Terrain::UpdateY()
{

}

Terrain::~Terrain()
{

}

} /* namespace peach */
