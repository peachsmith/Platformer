#ifndef HITBOX_H_
#define HITBOX_H_

namespace peach
{

/**
 * a class representing an object's hit box
 */
class HitBox
{
protected:
	float x;
	float y;
	float x_bound;
	float y_bound;
public:
	HitBox();
	HitBox(float x, float y, float x_bound, float y_bound);
	virtual ~HitBox();

	float GetX()
	{
		return x;
	}

	void SetX(float x)
	{
		HitBox::x = x;
	}

	float GetY()
	{
		return y;
	}

	void SetY(float y)
	{
		HitBox::y = y;
	}

	float GetXBound()
	{
		return x_bound;
	}

	void SetXBound(float x_bound)
	{
		HitBox::x_bound = x_bound;
	}

	float GetYBound()
	{
		return y_bound;
	}

	void SetYBound(float y_bound)
	{
		HitBox::x_bound = y_bound;
	}

};

} /* namespace peach */

#endif /* HITBOX_H_ */
