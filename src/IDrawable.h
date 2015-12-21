/*
 * IDrawable.h
 *
 *  Created on: Dec 13, 2015
 *      Author: jepye
 */

#ifndef IDRAWABLE_H_
#define IDRAWABLE_H_

namespace peach
{

/**
 * an interface for objects that can be rendered on screen
 */
class IDrawable
{
public:
	IDrawable()
	{
	}
	virtual ~IDrawable()
	{
	}
	virtual void Render() = 0;
};

} /* namespace peach */

#endif /* IDRAWABLE_H_ */
