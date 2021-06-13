#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mCnt(0)
	{
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mCnt; i++)
		{
			mPerson[i] = nullptr;
			delete mPerson[i];
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person == nullptr)
		{
			return false;
		}

		////Overlap Test
		//for (int i = 0; i < mCnt; i++)
		//{
		//	if (mPerson[i]->GetName() == person->GetName() && mPerson[i]->GetWeight() == person->GetWeight())
		//	{
		//		return false;
		//	}
		//}

		if (mCnt < mMaxPassengersCount)
		{
			mPerson[mCnt++] = person;
			return true;
		}

		return false;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i < mCnt)
		{
			if (i != mCnt - 1)
			{

				for (int cnt = i; cnt < mCnt - 1; cnt++)
				{
					mPerson[cnt] = mPerson[cnt + 1];
				}
			}
			mPerson[--mCnt] = nullptr;
			return true;
		}

		return false;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mCnt;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i > mCnt)
		{
			return NULL;
		}
		return mPerson[i];
	}
}