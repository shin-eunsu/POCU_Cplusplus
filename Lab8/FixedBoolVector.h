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

		bool Add(bool data)
		{
			if (mSize >= N)
			{
				return false;
			}

			mArray[mSize++] = data;
			return true;
		}

		bool Remove(bool data)
		{
			for (size_t i = 0; i < mSize; i++)
			{
				if (mArray[i] == data)
				{
					for (size_t j = i; j < mSize - 1; j++)
					{
						mArray[j] = mArray[j + 1];
					}
					mSize--;
					return true;
				}
			}
			return false;
		}

		bool Get(unsigned int index)
		{
			return mArray[index];
		}

		bool operator[](unsigned int index)
		{
			return mArray[index];
		}

		int GetIndex(bool data)
		{
			for (size_t i = 0; i < mSize; i++)
			{
				if (mArray[i] == data)
				{
					return i;
				}
			}
			return -1;
		}

		size_t GetSize()
		{
			return mSize;
		}

		size_t GetCapacity()
		{
			return N;
		}

	private:
		size_t mSize;
		uint32_t mArray[N];
	};

}