#ifndef ENTITY_H_
#define ENTITY_H_

#include "peach_base.h"

namespace peach
{

class Entity
{
private:
	int id;
	bool alive;
	bool collidable;

protected:

	// position
	float x;
	float y;

	// velocity
	float x_vel;
	float y_vel;

	// direction
	float x_dir;
	float y_dir;

	// hit box
	float x_bound;
	float y_bound;

	// jumping
	bool jumping;

	// sprite sheet
	void* sprite_sheet;

public:
	Entity();
	Entity(int id, bool alive, bool collidable, float x, float y, float x_vel, float y_vel, float x_dir, float y_dir, float x_bound, float y_bound);
	virtual ~Entity();

	void virtual UpdateX();
	void virtual UpdateY();
	void virtual Render();
	void virtual Collide(int object_id);
	void virtual SlowDown();
	void virtual Jump();

	int CheckCollision(peach::Entity* other, float& x_depth, float& y_depth);

	bool GetJumping()
	{
		return jumping;
	}

	void SetJumping(bool jumping)
	{
		Entity::jumping = jumping;
	}

	int GetID()
	{
		return id;
	}
	void SetID(int id)
	{
		Entity::id = id;
	}
	bool GetAlive()
	{
		return alive;
	}
	void SetAlive(bool alive)
	{
		Entity::alive = alive;
	}
	bool GetCollidable()
	{
		return collidable;
	}
	void SetCollidable(bool collidable)
	{
		Entity::collidable = collidable;
	}

	float GetX()
	{
		return x;
	}
	float GetY()
	{
		return y;
	}

	void SetX(float x)
	{
		Entity::x = x;
	}
	void SetY(float y)
	{
		Entity::y = y;
	}

	float GetXVel()
	{
		return x_vel;
	}

	float GetYVel()
	{
		return y_vel;
	}

	void SetXVel(int x_vel)
	{
		Entity::x_vel = x_vel;
	}

	void SetYVel(int y_vel)
	{
		Entity::y_vel = y_vel;
	}

	float GetXDir()
	{
		return x_dir;
	}
	float GetYDir()
	{
		return y_dir;
	}

	void SetXDir(float x_dir)
	{
		Entity::x_dir = x_dir;
	}
	void SetYDir(float y_dir)
	{
		Entity::y_dir = y_dir;
	}

	float GetXBound()
	{
		return x_bound;
	}
	float GetYBound()
	{
		return y_bound;
	}

	void SetXBound(float x_bound)
	{
		Entity::x_bound = x_bound;
	}
	void SetYBound(float y_bound)
	{
		Entity::y_bound = y_bound;
	}

	void* GetSpriteSheet()
	{
		return sprite_sheet;
	}

	void SetSpriteSheet(void* sprite_sheet)
	{
		Entity::sprite_sheet = sprite_sheet;
	}

};

} /* namespace peach */

#endif /* ENTITY_H_ */
