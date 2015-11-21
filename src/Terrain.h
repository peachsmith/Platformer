#ifndef TERRAIN_H_
#define TERRAIN_H_

#include "Entity.h"

namespace peach
{

class Terrain: public Entity
{
public:
	Terrain();
	Terrain(bool alive, bool collidable, float x, float y, float x_vel, float y_vel, float x_dir, float y_dir, float x_bound, float y_bound);
	~Terrain();

	void Render();               // override
	void Collide(int object_id); // override
	void UpdateX();              // override
	void UpdateY();              // override
};

} /* namespace peach */

#endif /* TERRAIN_H_ */
