#include "Player.h"
#include <iostream>

namespace peach
{

Player::Player()
{
	jumping = false;
}

Player::Player(bool alive, bool collidable, float x, float y, float x_vel, float y_vel, float x_dir, float y_dir, float x_bound, float y_bound)
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
}

Player::~Player()
{

}

void Player::UpdateX()
{
	x += x_vel;
//	float dif = x - (int) x;
//	if ((div > 0 && dif < .5) || (dif < 0 && dif > -.5))
//		x = (int) x;
//	else
//		x = (int) x + 1;

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
	al_draw_filled_rectangle(x, y, x + x_bound, y + y_bound, al_map_rgb(255 * ((int) GetAlive() ^ 1), 255 * GetAlive(), 0));
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
		//x_dir = -1;
		if (x_vel > -2)
			x_vel -= 1;
		break;
	case 3:         // right
		//x_dir = 1;
		if (x_vel < 2)
			x_vel += 1;
		break;
	default:
		break;
	}
}

}
