#pragma once
#include <iostream>

using namespace std;

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<bool, N>& other);
		bool Add(const bool& bData);
		bool Remove(const bool& bData);
		const bool Get(unsigned int index) const;
		bool operator[](unsigned int index);
		int GetIndex(bool bData) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		enum { MAX = 32 };
		size_t mSize;
		uint32_t mArray[((N - 1) / MAX) + 1];
	};


	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
		memset(mArray, 0, sizeof(mArray));
	}

	template<size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& bOther)
		: mSize(bOther.mSize)
		, mArray(bOther.mArray)
	{
		memset(mArray, 0, sizeof(mArray));
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool& bData)
	{
		if (mSize >= N)
		{
			return false;
		}

		unsigned int index = mSize / MAX;
		unsigned int bitIndex = mSize % MAX;

		if (bData)
		{
			mArray[index] |= (1 << bitIndex);
		}
		else
		{
			mArray[index] &= ~(1 << bitIndex);
		}
		mSize++;
		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool& bData)
	{
		const unsigned int maxIndex = ((mSize - 1) / MAX) + 1;

		//for (size_t i = 0; i < maxIndex; i++)
		//{
		//	for (size_t j = 0; j < mSize && j < MAX; j++)
		//	{
		//		if ((mArray[i] & (1 << j)) > 0)
		//		{
		//			if (bData)
		//			{
		//				mArray[i] >> (j + 1);
		//			}
		//		}
		//		else
		//		{
		//			if (!bData)
		//			{

		//			}
		//		}
		//	}
		//}

		return false;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::Get(unsigned int index) const
	{
		unsigned int intIndex = index / MAX;
		unsigned int bitIndex = index % MAX;

		return mArray[intIndex] & (1 << bitIndex);
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		unsigned int intIndex = index / MAX;
		unsigned int bitIndex = index % MAX;

		return mArray[intIndex] & (1 << bitIndex);
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(bool bData) const
	{
		const unsigned int maxIndex = ((mSize - 1) / MAX) + 1;

		for (size_t i = 0; i < maxIndex; i++)
		{
			for (size_t j = 0; j < MAX && j < mSize; j++)
			{
				if ((mArray[i] & (1 << j)) > 0)
				{
					if (bData)
					{
						return (i * MAX) + j;
					}
				}
				else
				{
					if (!bData)
					{
						return (i * MAX) + j;
					}
				}
			}
		}

		return -1;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}