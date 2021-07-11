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
			, mbArray{{}}
		{

		}

		bool Add(bool bData)
		{
			if (mSize >= N)
			{
				return false;
			}

			mbArray[mSize++] = bData;
			return true;
		}

		bool Remove(bool bData)
		{
			for (size_t i = 0; i < mSize; i++)
			{
				if (mbArray[i] == bData)
				{
					for (size_t j = i; j < mSize - 1; j++)
					{
						mbArray[j] = mbArray[j + 1];
					}
					mbArray[mSize - 1] = 0;
					mSize--;
					return true;
				}
			}
			return false;
		}

		bool Get(unsigned int index) const
		{
			return mbArray[index];
		}

		bool operator[](unsigned int index)
		{
			return mbArray[index];
		}


		int GetIndex(bool bData) const
		{
			for (size_t i = 0; i < mSize; i++)
			{
				if (mbArray[i] == bData)
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
		bool mbArray[N];
	};

}