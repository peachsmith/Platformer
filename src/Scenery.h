#ifndef SCENERY_H_
#define SCENERY_H_

#include "Entity.h"

namespace peach
{

class Scenery: public Entity
{
private:
	void* sprite_sheet;
	int sheet_x;
	int sheet_y;
	int x_scale;
	int y_scale;
public:
	Scenery();
	Scenery(float x, float y, float x_bound, float y_bound, int sheet_x, int sheet_y, void* sprite_sheet);
	virtual ~Scenery();

	void Render();

	int GetSheetX()
	{
		return sheet_x;
	}

	void SetSheetX(int sheet_x)
	{
		Scenery::sheet_x = sheet_x;
	}

	int GetSheetY()
	{
		return sheet_y;
	}

	void SetSheetY(int sheet_y)
	{
		Scenery::sheet_y = sheet_y;
	}
};

} /* namespace peach */

#endif /* SCENERY_H_ */
