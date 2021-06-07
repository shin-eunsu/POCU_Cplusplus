#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		for (int num : v)
		{
			sum += num;
		}
		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		int minVal = INT_MAX;

		for (int num : v)
		{
			minVal = std::min(minVal, num);
		}

		return minVal;
	}

	int Max(const std::vector<int>& v)
	{
		int maxVal = INT_MIN;

		for (int num : v)
		{
			maxVal = std::max(maxVal, num);
		}

		return maxVal;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.empty())
		{
			return 0;
		}

		int cnt = 0;
		int sum = 0;

		for (int num : v)
		{
			cnt++;
			sum += num;
		}

		return sum / static_cast<float>(cnt);
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.empty())
		{
			return 0;
		}

		std::vector<std::vector<int>> dt;
		dt.push_back(std::vector<int>(2, 0));

		bool bNewRow = true;
		int cnt = 0;
		int maxCnt = 0;
		int maxKey = 0;
		for (int num : v)
		{
			int keyCnt = 0;
			for (std::vector<int> key : dt)
			{
				if (key[0] == num)
				{
					if (maxCnt < ++dt[keyCnt][1])
					{
						maxCnt = dt[keyCnt][1];
						maxKey = key[0];
						bNewRow = false;
						break;
					}					
				}
				keyCnt++;
				bNewRow = true;
			}
			if (bNewRow)
			{
				if (cnt != 0)
				{
					dt.push_back(std::vector<int>(2, 0));
				}
				bNewRow = false;
				dt[cnt][0] = num;
				dt[cnt][1] = 1;
				cnt++;
			}
		}
		return maxKey;
	}

	void SortDescending(std::vector<int>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			for (size_t j = 0; j < v.size() - 1; j++)
			{
				int min = std::min(v[j], v[j + 1]);
				int max = std::max(v[j], v[j + 1]);
				v[j] = max;
				v[j + 1] = min;
			}
		}
	}
}