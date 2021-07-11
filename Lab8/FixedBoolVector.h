#pragma once
#include <iostream>

using namespace std;

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector()
			: mSize(0)
			, bArray{{}}
		{

		}

		bool Add(bool bData)
		{
			if (mSize >= N)
			{
				return false;
			}

			bArray[mSize++] = bData;
			return true;
		}

		bool Remove(bool bData)
		{
			for (size_t i = 0; i < mSize; i++)
			{
				if (bArray[i] == bData)
				{
					for (size_t j = i; j < mSize - 1; j++)
					{
						bArray[j] = bArray[j + 1];
					}
					//mArray[mSize - 1] = 0;
					mSize--;
					return true;
				}
			}
			return false;
		}

		bool Get(unsigned int index) const
		{
			return bArray[index];
		}

		bool operator[](unsigned int index)
		{
			return bArray[index];
		}


		int GetIndex(bool bData) const
		{
			for (size_t i = 0; i < mSize; i++)
			{
				if (bArray[i] == bData)
				{
					return i;
				}
			}
			return -1;
		}

		size_t GetSize() const
		{
			return mSize;
		}

		size_t GetCapacity() const
		{
			return N;
		}

	private:
		size_t mSize;
		bool bArray[N];
	};

}