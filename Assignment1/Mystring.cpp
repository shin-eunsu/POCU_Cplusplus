#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		:mSize(MyStrlen(s) + 1)
	{
		mString = new char[mSize];
		CharCpy(mString, s, mSize);
	}

	MyString::MyString(const MyString& other)
		: mSize(other.mSize)
	{
		mString = new char[mSize];
		CharCpy(mString, other.mString, mSize);
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		int strLen = 0;

		while (mString[strLen] != '\0')
		{
			strLen++;
		}
		return strLen;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		int sSize = MyStrlen(s);
		char* appendStr = new char[mSize + sSize];

		size_t cnt;
		for (cnt = 0; cnt < mSize - 1; cnt++)
		{
			appendStr[cnt] = mString[cnt];
		}
		for (size_t sCnt = 0; sCnt < sSize; sCnt++)
		{
			appendStr[cnt++] = s[sCnt];
		}
		appendStr[cnt] = '\0';

		delete[] mString;
		mString = new char[mSize + sSize];

		CharCpy(mString, appendStr, mSize + sSize);

		delete[] appendStr;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString cat(mString);
		cat.Append(other.mString);

		return MyString(cat.mString);
	}

	int MyString::IndexOf(const char* s)
	{
		int returnVal = -1;
		for (int i = 0; i < MyStrlen(mString); i++)
		{
			if (mString[i] == s[0])
			{
				returnVal = i;
				break;
			}
		}
		return returnVal;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int returnVal = -1;
		for (int i = MyStrlen(mString); i > 0; i--)
		{
			if (mString[i] == s[0])
			{
				returnVal = i;
				break;
			}
		}
		return returnVal;
	}

	void MyString::Interleave(const char* s)
	{
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}


	int MyString::MyStrlen(const char* str)
	{
		int strLen = 0;

		while (str[strLen] != '\0')
		{
			strLen++;
		}
		return strLen;
	}

	void MyString::CharCpy(char* dst, const char* src, size_t srcSize)
	{
		size_t cnt;
		for (cnt = 0; cnt < srcSize; cnt++)
		{
			dst[cnt] = src[cnt];
		}
	}
}