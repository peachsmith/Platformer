#ifndef ILEVEL1_H_
#define ILEVEL1_H_

#include "IDrawable.h"

namespace peach
{
class ILevel: public IDrawable
{
public:
	ILevel()
	{
	}
	~ILevel()
	{
	}
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual int GetStatus() = 0;
	virtual void SetStatus(int status) = 0;
};
}

#endif /* ILEVEL_H_ */
