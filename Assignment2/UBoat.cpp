#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		int speed = static_cast<int>(round(550 - GetPassengersCount() / 10.0));
		return std::max(speed, 200);
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		unsigned int passengerCount = GetPassengersCount();
		unsigned int sumWeight = 0;
		for (unsigned int i = 0; i < passengerCount; i++)
		{
			sumWeight += GetPassenger(i)->GetWeight();
		}

		double speed = round(500 * log((150.0 + sumWeight) / 150.0) + 30);
		return static_cast<int>(speed);
	}
	
	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int sailSpeed = GetSailSpeed();
		unsigned int diveSpeed = GetDiveSpeed();

		if (sailSpeed > diveSpeed)
		{
			return sailSpeed;
		}
		else
		{
			return diveSpeed;
		}
	}
}