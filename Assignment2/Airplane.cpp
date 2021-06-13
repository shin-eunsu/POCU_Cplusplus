#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int driveSpeed = GetDriveSpeed();

		if (flySpeed > driveSpeed)
		{
			return flySpeed;
		}
		else
		{
			return driveSpeed;
		}
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		unsigned int passengerCount = GetPassengersCount();
		unsigned int sumWeight = 0;
		for (unsigned int i = 0; i < passengerCount; i++)
		{
			sumWeight += GetPassenger(i)->GetWeight();
		}

		double speed = round(200 * exp((800 - sumWeight) / 500.0));
		return static_cast<int>(speed);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		unsigned int passengerCount = GetPassengersCount();
		unsigned int sumWeight = 0;
		for (unsigned int i = 0; i < passengerCount; i++)
		{
			sumWeight += GetPassenger(i)->GetWeight();
		}

		double speed = round(4 * exp((400 - sumWeight) / 70.0));
		return static_cast<int>(speed);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		for (unsigned int i = GetPassengersCount(); i > 0; i--)
		{
			bp.AddPassenger(GetPassenger(i - 1));
			RemovePassenger(i - 1);
		}
		for (unsigned int i = boat.GetPassengersCount(); i > 0; i--)
		{
			bp.AddPassenger(boat.GetPassenger(i - 1));
			boat.RemovePassenger(i - 1);
		}
		return bp;
	}
}