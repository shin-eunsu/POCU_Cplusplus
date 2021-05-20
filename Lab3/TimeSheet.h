#pragma once
#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& other);
		~TimeSheet();
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;
		TimeSheet& operator=(const TimeSheet& rhs);

	private:
		char* mName;
		int* mTime;
		int mCnt;
		size_t mNameSize ;
		unsigned int mMaxEntries;
		std::string mStr;

		const int minTime = 1;
		const int maxTime = 10;
	};
}