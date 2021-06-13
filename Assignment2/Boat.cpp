#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetSailSpeed() const
	{
		int speed = 800 - (10 * GetPassengersCount());
		return std::max(speed, 20);
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		for (unsigned int i = GetPassengersCount(); i > 0; i--)
		{
			bp.AddPassenger(GetPassenger(i - 1));
			RemovePassenger(i - 1);
		}
		for (unsigned int i = plane.GetPassengersCount(); i > 0; i--)
		{
			bp.AddPassenger(plane.GetPassenger(i - 1));
			plane.RemovePassenger(i - 1);
		}
		return bp;
	}
}