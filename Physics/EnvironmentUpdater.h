#ifndef environmentupdater_h
#define environmentupdater_h

#include "PhysicalValue.h"

class EnvironmentUpdater
{
private:
	PhysicalValue* g;
public:
	EnvironmentUpdater()
	{
		g = new PhysicalValue(-9.807, 1, 0, -2);
	}
};

#endif
