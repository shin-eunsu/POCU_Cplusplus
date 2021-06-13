#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina* deusExMachina = new DeusExMachina();
		return deusExMachina;
	}

	void DeusExMachina::Travel() const
	{
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (deusCnt > 10)
		{
			return false;
		}


		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}
}