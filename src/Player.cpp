#include "Player.h"
#include <iostream>

namespace peach
{

Player::Player() :
		sprite_row(0)
{
	jumping = false;
}

Player::Player(bool alive, bool collidable, float x, float y, float x_vel, float y_vel, float x_dir, float y_dir, float x_bound, float y_bound) :
		sprite_row(0)
{
	SetID(peach::PLAYER);
	SetAlive(alive);
	SetCollidable(collidable);

	Player::x = x;
	Player::y = y;
	Player::x_vel = x_vel;
	Player::y_vel = y_vel;
	Player::x_dir = x_dir;
	Player::y_dir = y_dir;
	Player::x_bound = x_bound;
	Player::y_bound = y_bound;

	jumping = false;

	sprite_sheet = 0;
}

Player::Player(bool alive, bool collidable, float x, float y, float x_vel, float y_vel, float x_dir, float y_dir, float x_bound, float y_bound, void* sprite_sheet) :
		sprite_row(0)
{
	SetID(peach::PLAYER);
	SetAlive(alive);
	SetCollidable(collidable);

	Player::x = x;
	Player::y = y;
	Player::x_vel = x_vel;
	Player::y_vel = y_vel;
	Player::x_dir = x_dir;
	Player::y_dir = y_dir;
	Player::x_bound = x_bound;
	Player::y_bound = y_bound;

	jumping = false;

	Player::sprite_sheet = sprite_sheet;
}

Player::~Player()
{

}

void Player::UpdateX()
{
	x += x_vel;

}

void Player::UpdateY()
{
	if (y_vel < 4)
		y_vel += .2;
	if (y_vel > 4)
		y_vel = 4;
	y += y_vel;
}

void Player::Render()
{
	if (!sprite_sheet)
	{
		al_draw_filled_rectangle(x, y, x + x_bound, y + y_bound, al_map_rgb(0, 255, 0));
	}
	else
	{
		//al_draw_bitmap_region((ALLEGRO_BITMAP*)sprite_sheet, 0, 20 * sprite_row, 20, 20, x, y, 0);
		al_draw_scaled_bitmap((ALLEGRO_BITMAP*) sprite_sheet, 0, 20 * sprite_row, 20, 20, x - 12, y - 8, 40, 40, 0);
		//al_draw_rectangle(x, y, x + x_bound, y + y_bound, al_map_rgb(255, 0, 0), 1);
	}
}

void Player::Collide(int object_id)
{

}

void Player::SlowDown()
{
	if (x_vel < 0)
	{
		if (x_vel + .2 >= 0)
			x_vel = 0;
		else
			x_vel += 1;
	}
	else if (x_vel > 0)
	{
		if (x_vel - .2 <= 0)
			x_vel = 0;
		else
			x_vel -= 1;
	}
}

void Player::Jump()
{
	if (!jumping)
	{
		jumping = true;
		y_vel -= 6;
	}
}

void Player::Move(int direction)
{
	switch (direction)
	{
	case 0:         // up
		y_dir = -1;
		break;
	case 1:         // down
		y_dir = 1;
		break;
	case 2:         // left
		x_dir = -1;
		sprite_row = 1;
		if (x_vel > -2)
			x_vel -= 1;
		break;
	case 3:         // right
		x_dir = 1;
		sprite_row = 0;
		if (x_vel < 2)
			x_vel += 1;
		break;
	default:
		break;
	}
}

}
