#pragma once

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		bool Add(const T& data);
		bool Remove(const T& data);
		T& Get(unsigned int index);
		T& operator[](unsigned int index);
		T& operator=(const T& data);
		int GetIndex(const T& data);
		size_t GetSize();
		size_t GetCapacity();

	private:
		size_t mSize;
		T mArray[N];
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
		, mArray{{}}
	{

	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& data)
	{
		if (mSize >= N)
		{
			return false;
		}

		mArray[mSize++] = data;
		return true;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& data)
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

	template<typename T, size_t N>
	T& FixedVector<T, N>::Get(unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator=(const T& data)
	{
		return data;
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& data)
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

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize()
	{
		return mSize;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}
}