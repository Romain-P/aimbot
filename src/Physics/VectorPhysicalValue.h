#ifndef vectorphysicalvalue_h
#define vectorphysicalvalue_h

#include "PhysicalValue.h"
#include "../Utils/Vector3.h"

class VectorPhysicalValue : public PhysicalValue
{
private:
	Vector3 direction;
public:
	VectorPhysicalValue(Vector3 direction, float value, int length, int mass, int time) :
		PhysicalValue(value, length, mass, time)
	{
		this->direction = direction;
	}
};

#endif
