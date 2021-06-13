#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
		, mBoatplaneMaxCnt(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int passengerCount = GetPassengersCount();
		unsigned int sumWeight = 0;
		for (unsigned int i = 0; i < passengerCount; i++)
		{
			sumWeight += GetPassenger(i)->GetWeight();
		}

		double speed = round(150 * exp((500 - sumWeight) / 300.0));
		return static_cast<int>(speed);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		int speed = static_cast<int>(round(800 - (1.7 * GetPassengersCount())));
		return std::max(speed, 20);
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int sailSpeed = GetSailSpeed();

		if (flySpeed > sailSpeed)
		{
			return flySpeed;
		}
		else
		{
			return sailSpeed;
		}
	}
}