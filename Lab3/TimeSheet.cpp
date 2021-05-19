#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mNameSize(strlen(name) + 1)
		, mMaxEntries(maxEntries) // maxEntries : 저장가능 수량
		, mSaveTime{ '\0' }
		, mCnt(0)
	{
		mName = new char[mNameSize];
		memcpy(mName, name, mNameSize);
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		: mNameSize(other.mNameSize)
		, mMaxEntries(other.mMaxEntries)
		, mSaveTime{ '\0' }
		, mCnt(0)
	{
		mName = new char[mNameSize];
		memcpy(mName, other.mName, mNameSize);
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		mNameSize = rhs.mNameSize;
		mMaxEntries = rhs.mMaxEntries;
		mCnt = rhs.mCnt;
		memcpy(mSaveTime, rhs.mSaveTime, BUFSIZ);

		char* tmpName = new char[rhs.mNameSize];
		memcpy(tmpName, rhs.mName, rhs.mNameSize);
		delete[] mName;
		mName = new char[rhs.mNameSize];
		memcpy(mName, tmpName, rhs.mNameSize);
		delete[] tmpName;

		return *this;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mName;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours >= minTime && timeInHours <= maxTime)
		{
			mSaveTime[mCnt++] = timeInHours;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		unsigned int cnt = mCnt;
		if (index >= cnt)
		{
			return -1;
		}
		return mSaveTime[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int sum = 0;
		for (int i = 0; i < mCnt; i++)
		{
			sum += mSaveTime[mCnt];
		}
		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		int totalTime = GetTotalTime();
		float avg = totalTime / static_cast<float>(mCnt);

		return avg;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float std;
		float var;
		float avg = GetAverageTime();
		float sum = 0;

		for (int i = 0; i < mCnt; i++)
		{
			sum += powf(static_cast<float>(mSaveTime[mCnt]) - avg, 2);
		}
		var = sum / static_cast<float>(mCnt);
		std = sqrtf(var);

		return std;
	}

	const std::string& TimeSheet::GetName() const
	{

		return mName;
	}
}