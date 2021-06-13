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
		if (mDeusCnt > 10 || vehicle == nullptr)
		{
			return false;
		}

		if (mDeusCnt < MAXCOUNT)
		{
			//mVehicle[mDeusCnt++] = vehicle;
			return true;
		}
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i < mDeusCnt)
		{
			if (i != mDeusCnt - 1)
			{
				for (unsigned int cnt = i; cnt < mDeusCnt - 1; cnt++)
				{
					mVehicle[cnt] = mVehicle[cnt + 1];
				}
			}
			mVehicle[--mDeusCnt] = nullptr;
			return true;
		}

		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}
}