#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"

namespace peach
{

class Player: public Entity
{
public:
	Player();
	Player(bool alive, bool collidable, float x, float y, float x_vel,
			float y_vel, float x_dir, float y_dir, float x_bound,
			float y_bound);
	~Player();

	void UpdateX();                      // override
	void UpdateY();                      // override
	void Render();                       // override
	void Collide(int object_id);         // override
	void SlowDown();                     // override
	void Jump();                         // override

	void Move(int direction);

};

} /* namespace peach */

#endif /* PLAYER_H_ */
