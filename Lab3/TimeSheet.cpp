#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mNameSize(strlen(name) + 1)
		, mMaxEntries(maxEntries) // maxEntries : 저장가능 수량
		, mCnt(0)
	{
		mName = new char[mNameSize];
		memcpy(mName, name, mNameSize);
		mTime = new int[maxEntries] {'\0'};
		mStr = mName;
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		: mNameSize(other.mNameSize)
		, mMaxEntries(other.mMaxEntries)
		, mCnt(other.mCnt)
	{
		mName = new char[other.mNameSize];
		memcpy(mName, other.mName, other.mNameSize);
		mTime = new int[other.mMaxEntries] {'\0'};
		memcpy(mTime, other.mTime, other.mMaxEntries);
		mStr = other.mName;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mName;
		delete[] mTime;
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		mNameSize = rhs.mNameSize;
		mMaxEntries = rhs.mMaxEntries;
		mCnt = rhs.mCnt;
		memcpy(mTime, rhs.mTime, rhs.mMaxEntries);

		char* tmpName = new char[rhs.mNameSize];
		memcpy(tmpName, rhs.mName, rhs.mNameSize);
		delete[] mName;
		mName = new char[rhs.mNameSize];
		memcpy(mName, tmpName, rhs.mNameSize);
		delete[] tmpName;

		return *this;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		unsigned int cnt = mCnt;
		if (timeInHours >= MINTIME && timeInHours <= MAXTIME && cnt < mMaxEntries)
		{
			mTime[mCnt++] = timeInHours;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		unsigned int cnt = mCnt;
		if (index >= cnt)
		{
			return -1;
		}
		return mTime[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int sum = 0;
		for (int i = 0; i < mCnt; i++)
		{
			sum += mTime[i];
		}
		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		int totalTime = GetTotalTime();
		float avg = 0;
		if (mCnt != 0)
		{
			avg = totalTime / static_cast<float>(mCnt);
		}

		return avg;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float avg = GetAverageTime();
		float var = 0.0f;
		float std = 0.0f;
		float sum = 0.0f;

		for (int i = 0; i < mCnt; i++)
		{
			sum += powf(static_cast<float>(mTime[i]) - avg, 2);
		}
		if (mCnt != 0)
		{
			var = sum / static_cast<float>(mCnt);
		}
		std = sqrtf(var);

		return std;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mStr;
	}
}