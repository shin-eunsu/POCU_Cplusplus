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

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mCnt(other.mCnt)
	{
		for (unsigned int i = 0; i < mCnt; i++)
		{
			const char* name = other.mPerson[i]->GetName().c_str();
			mPerson[i] = new Person(name, other.mPerson[i]->GetWeight());
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& rhs)
	{
		mCnt = rhs.mCnt;
		mMaxPassengersCount = rhs.mMaxPassengersCount;

		for (unsigned int i = 0; i < mCnt; i++)
		{
			const char* name = rhs.mPerson[i]->GetName().c_str();
			mPerson[i] = new Person(name, rhs.mPerson[i]->GetWeight());
		}
		return *this;
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
				for (unsigned int cnt = i; cnt < mCnt - 1; cnt++)
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