#ifndef ICOLLIDABLE_H_
#define ICOLLIDABLE_H_

#include "HitBox.h"

namespace peach
{

/**
 * an interface for objects that can collide with one another
 */
class ICollidable
{
public:
	ICollidable()
	{
	}
	virtual ~ICollidable()
	{
	}

	virtual void Collide(int object_id) = 0;
	virtual int CheckCollision(peach::HitBox* other, float& x_depth, float& y_depth) = 0;

};

} /* namespace peach */

#endif /* ICOLLIDABLE_H_ */
