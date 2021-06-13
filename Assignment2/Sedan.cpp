#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
	{
	}

	Sedan::~Sedan()
	{
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer != nullptr)
		{
			return false;
		}

		mTrailer = trailer;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == nullptr)
		{
			return false;
		}

		mTrailer = nullptr;
		return true;
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int passengerCount = GetPassengersCount();
		unsigned int sumWeight = 0;
		for (unsigned int i = 0; i < passengerCount; i++)
		{
			sumWeight += GetPassenger(i)->GetWeight();
		}
		sumWeight += mTrailer->GetWeight();

		unsigned int speed = 0;

		if (sumWeight <= 80)
		{
			speed = 480;
		}
		else if (sumWeight > 80)
		{
			speed = 458;
		}
		else if (sumWeight > 160)
		{
			speed = 400;
		}
		else if (sumWeight > 260)
		{
			speed = 380;
		}
		else if (sumWeight > 350)
		{
			speed = 300;
		}

		return speed;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}