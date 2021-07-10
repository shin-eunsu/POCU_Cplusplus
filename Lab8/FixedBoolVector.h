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
			, mArray{{}}
		{

		}

		bool Add(bool bData)
		{
			if (mSize >= N)
			{
				return false;
			}

			mArray[mSize++] = bData;
			return true;
		}

		bool Remove(bool bData)
		{
			for (size_t i = 0; i < mSize; i++)
			{
				if (mArray[i] == bData)
				{
					for (size_t j = i; j < mSize - 1; j++)
					{
						mArray[j] = mArray[j + 1];
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
			return mArray[index];
		}

		bool operator[](unsigned int index)
		{
			return mArray[index];
		}


		int GetIndex(bool bData)
		{
			for (size_t i = 0; i < mSize; i++)
			{
				if (mArray[i] == bData)
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
		uint32_t mArray[N];
	};

}