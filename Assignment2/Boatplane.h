#pragma once

#include "Vehicle.h"
#include "IDrivable.h"
#include "IFlyable.h"

namespace assignment2
{
	class Boatplane: public Vehicle, public IFlyable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;
	};
}