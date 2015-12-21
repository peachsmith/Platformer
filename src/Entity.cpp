#include "Entity.h"
#include <iostream>

namespace peach
{

Entity::Entity() :
		jumping(false), sprite_sheet(0), max_frame(0), current_frame(0), frame_count(0), frame_delay(0)
{
	id = 0;
	alive = true;
	collidable = true;

	x = 0;
	y = 0;
	x_vel = 0;
	y_vel = 0;
	x_dir = 0;
	y_dir = 0;
	x_bound = 0;
	y_bound = 0;
}

Entity::Entity(int id, bool alive, bool collidable, float x, float y, float x_vel, float y_vel, float x_dir, float y_dir, float x_bound, float y_bound) :
		jumping(false), sprite_sheet(0), max_frame(0), current_frame(0), frame_count(0), frame_delay(0)
{
	Entity::id = id;
	Entity::alive = alive;
	Entity::collidable = collidable;

	Entity::x = x;
	Entity::y = y;
	Entity::x_vel = x_vel;
	Entity::y_vel = y_vel;
	Entity::x_dir = x_dir;
	Entity::y_dir = y_dir;
	Entity::x_bound = x_bound;
	Entity::y_bound = y_bound;
}

Entity::~Entity()
{

}

void Entity::Render()
{

}

void Entity::Collide(int object_id)
{

}

void Entity::UpdateX()
{
	x += x_vel;
}

void Entity::UpdateY()
{
	y += y_vel;
}

void Entity::SlowDown()
{

}

void Entity::Jump()
{

}

/*
 *
 *     +----------+
 * +---|-+        |
 * |   | | other  |    x_depth = positive
 * +---|-+        |
 *     +----------+
 *
 *
 * +-----------+
 * |   other   |     y_depth = positive
 * |           |
 * |  +----+   |
 * +--|----|---+
 *    |    |
 *    +----+
 */
int Entity::CheckCollision(peach::HitBox* other, float& x_depth, float& y_depth)
{
	int collision = 0;
	float other_x = other->GetX();
	float other_y = other->GetY();

	int other_x_bound = other->GetXBound();
	int other_y_bound = other->GetYBound();

	if (x + x_bound > other_x)
		collision |= 1;
	if (x - other_x_bound < other_x)
		collision |= 2;
	if (y + y_bound > other_y)
		collision |= 4;
	if (y - other_y_bound < other_y)
		collision |= 8;

	if (x <= other_x && collision == 15)
	{
		x_depth = x + x_bound - other_x;
	}
	else if (x > other_x && collision == 15)
	{
		x_depth = x - other_x - other_x_bound;
	}
	else
		x_depth = 0;

	if (y <= other_y && collision == 15)
	{
		y_depth = y + y_bound - other_y;
	}
	else if (y > other_y && collision == 15)
	{
		y_depth = y - other_y - other_y_bound;
	}
	else
		y_depth = 0;

	return collision;
}

}
