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
		size_t sSize = MyStrlen(s);
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
		for (int i = 0; i < GetLength(); i++)
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
		int mStringSize = GetLength();
		int sSize = MyStrlen(s);

		int minSize = sSize;
		int maxSize = mStringSize;
		if (mStringSize < sSize)
		{
			minSize = mStringSize;
			maxSize = sSize;
		}
		char* str = new char[minSize + maxSize + 1];

		for (int i = 0; i < minSize; i++)
		{
			str[i * 2] = mString[i];
			str[(i * 2) + 1] = s[i];
		}

		int cnt = minSize;
		for (int i = minSize * 2; i < minSize + maxSize; i++)
		{
			if (mStringSize > sSize)
			{
				str[i] = mString[cnt++];
			}
			else
			{
				str[i] = s[cnt++];
			}
		}
		str[minSize + maxSize] = '\0';

		delete[] mString;
		mString = new char[minSize + maxSize + 1];
		CharCpy(mString, str, minSize + maxSize + 1);
		delete[] str;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		unsigned int mStringSize = GetLength();
		if (mStringSize > i)
		{
			char* str = new char[mStringSize];
			CharCpy(str, mString, i);
			for (int cnt = i; cnt < mStringSize - 1; cnt++)
			{
				str[cnt] = mString[cnt + 1];
			}
			str[mStringSize - 1] = '\0';

			delete[] mString;
			mString = new char[mStringSize];
			CharCpy(mString, str, mStringSize);

			delete[] str;
			return true;
		}
		else
		{
			return false;
		}
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		int mStringSize = GetLength();
		char addChar = ' ';

		if (totalLength > mStringSize)
		{
			char* str = new char[totalLength + 1];

			unsigned int addCnt = totalLength - mStringSize;
			for (unsigned int i = 0; i < addCnt; i++)
			{
				str[i] = addChar;
			}
			for (unsigned int i = addCnt; i < totalLength; i++)
			{
				str[i] = mString[i - addCnt];
			}
			str[totalLength] = '\0';

			delete[] mString;
			mString = new char[totalLength + 1];
			CharCpy(mString, str, totalLength + 1);
			delete[] str;
		}
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		int mStringSize = GetLength();
		char addChar = c;

		if (totalLength > mStringSize)
		{
			char* str = new char[totalLength + 1];

			unsigned int addCnt = totalLength - mStringSize;
			for (unsigned int i = 0; i < addCnt; i++)
			{
				str[i] = addChar;
			}
			for (unsigned int i = addCnt; i < totalLength; i++)
			{
				str[i] = mString[i - addCnt];
			}
			str[totalLength] = '\0';

			delete[] mString;
			mString = new char[totalLength + 1];
			CharCpy(mString, str, totalLength + 1);
			delete[] str;
		}
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		int mStringSize = GetLength();
		char addChar = ' ';

		if (totalLength > mStringSize)
		{
			char* str = new char[totalLength + 1];
			unsigned int addCnt = totalLength - mStringSize;

			CharCpy(str, mString, mStringSize);
			for (unsigned int i = mStringSize; i < totalLength; i++)
			{
				str[i] = addChar;
			}
			str[totalLength] = '\0';

			delete[] mString;
			mString = new char[totalLength + 1];
			CharCpy(mString, str, totalLength + 1);
			delete[] str;
		}
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		int mStringSize = GetLength();
		char addChar = c;

		if (totalLength > mStringSize)
		{
			char* str = new char[totalLength + 1];
			unsigned int addCnt = totalLength - mStringSize;

			CharCpy(str, mString, mStringSize);
			for (unsigned int i = mStringSize; i < totalLength; i++)
			{
				str[i] = addChar;
			}
			str[totalLength] = '\0';

			delete[] mString;
			mString = new char[totalLength + 1];
			CharCpy(mString, str, totalLength + 1);
			delete[] str;
		}
	}

	void MyString::Reverse()
	{
		int mStringSize = GetLength();
		char tmp = NULL;

		for (int i = 0; i < mStringSize / 2; i++)
		{
			tmp = mString[i];
			mString[i] = mString[mStringSize - i - 1];
			mString[mStringSize - i - 1] = tmp;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		int mStringSize = GetLength();
		int rhsSize = rhs.GetLength();

		if (mStringSize == rhsSize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		return *this;
	}

	// ASCII : Dec		Hex
	// A ~ Z : 65 ~ 90  0x41 ~ 0x5A
	// a ~ z : 97 ~ 122 0x61 ~ 0x7A
	// ( - ) : 32		0x20
	void MyString::ToLower()
	{
		int mStringSize = GetLength();

		for (int i = 0; i < mStringSize; i++)
		{
			if ((mString[i] >= 0x41) && (mString[i] <= 0x5A)) //대문자
			{
				mString[i] += 0x20;
			}
		}
	}

	void MyString::ToUpper()
	{
		int mStringSize = GetLength();

		for (int i = 0; i < mStringSize; i++)
		{
			if ((mString[i] >= 0x61) && (mString[i] <= 0x7A)) //소문자
			{
				mString[i] -= 0x20;
			}
		}
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
		for (size_t cnt = 0; cnt < srcSize; cnt++)
		{
			dst[cnt] = src[cnt];
		}
	}
}