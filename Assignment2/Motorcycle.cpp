#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		unsigned int passengerCount = GetPassengersCount();
		unsigned int sumWeight = 0;
		for (unsigned int i = 0; i < passengerCount; i++)
		{
			sumWeight += GetPassenger(i)->GetWeight();
		}

		int speed = (0 - ((sumWeight / 15) ^ 3) + (2 * sumWeight) + 400);
		return speed;
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}