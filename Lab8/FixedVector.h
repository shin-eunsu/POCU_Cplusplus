#pragma once
#include <cstring>
namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<T, N>& other);
		bool Add(const T& data);
		bool Remove(const T& data);
		const T& Get(unsigned int index) const;
		T& operator[](unsigned int index);
		FixedVector<T, N>& operator=(const FixedVector<T, N>& other);
		int GetIndex(const T& data) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		T mArray[N];
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
		memset(mArray, 0, sizeof(T) * N);
	}

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector(const FixedVector<T, N>& other)
		: mSize(other.mSize)
	{
		memcpy(mArray, other.mArray, sizeof(T) * N);
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
				//mArray[mSize] = NULL;
				return true;
			}
		}
		return false;
	}

	template<typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int index) const
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector<T, N>& other)
	{
		mSize = other.mSize;
		memcpy(mArray, other.mArray, sizeof(T) * N);
		return *this;
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& data) const
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
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}