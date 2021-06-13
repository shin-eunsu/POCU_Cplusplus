#pragma once

#include "Vehicle.h"
#include "IDrivable.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane: public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;

	private:
		unsigned int mBoatplaneMaxCnt;
	};
}