/*
 * HitBox.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: jepye
 */

#include "HitBox.h"

namespace peach
{

HitBox::HitBox() :
		x(0), y(0), x_bound(0), y_bound(0)
{

}

HitBox::HitBox(float x, float y, float x_bound, float y_bound)
{
	HitBox::x = x;
	HitBox::y = y;
	HitBox::x_bound = x_bound;
	HitBox::y_bound = y_bound;
}

HitBox::~HitBox()
{

}

} /* namespace peach */
