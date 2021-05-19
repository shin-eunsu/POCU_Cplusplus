#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mSize(myStrlen(s) + 1)
	{
		mString = new char[mSize];
		charCpy(mString, s, mSize);
	}

	MyString::MyString(const MyString& other)
		: mSize(other.mSize)
	{
		mString = new char[mSize];
		charCpy(mString, other.mString, mSize);
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
		size_t sSize = myStrlen(s);

		if (sSize > 0)
		{
			char* appendStr = new char[mSize + sSize + 1];

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

			charCpy(mString, appendStr, mSize + sSize);

			delete[] appendStr;
		}
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString cat(mString);
		cat.Append(other.mString);

		return MyString(cat.mString);
	}

	int MyString::IndexOf(const char* s)
	{
		unsigned int mStringSize = GetLength();
		unsigned int sSize = myStrlen(s);
		int cnt = 0;

		if (s == nullptr || sSize > mStringSize)
		{
			return -1;
		}
		if (sSize == 0)
		{
			return 0;
		}

		for (unsigned int i = 0; i < mStringSize; i++)
		{
			if (mString[i] == s[cnt])
			{
				cnt++;
			}
			if (cnt == sSize)
			{
				return i - cnt + 1;
			}
		}
		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int mStringSize = myStrlen(mString);
		int sSize = myStrlen(s);
		int cnt = sSize - 1;

		if (s == nullptr || sSize > mStringSize)
		{
			return -1;
		}
		if (sSize == 0)
		{
			return mStringSize;
		}
		for (int i = mStringSize; i >= 0; i--)
		{
			if (mString[i] == s[cnt])
			{
				cnt--;
			}
			if (cnt == -1)
			{
				return i;
			}
		}
		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		int mStringSize = GetLength();
		int sSize = myStrlen(s);

		if (sSize > 0)
		{
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
			charCpy(mString, str, minSize + maxSize + 1);
			delete[] str;
		}
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		unsigned int mStringSize = GetLength();
		if (mStringSize > i)
		{
			char* str = new char[mStringSize];
			charCpy(str, mString, i);
			for (unsigned int cnt = i; cnt < mStringSize - 1; cnt++)
			{
				str[cnt] = mString[cnt + 1];
			}
			str[mStringSize - 1] = '\0';

			delete[] mString;
			mString = new char[mStringSize];
			charCpy(mString, str, mStringSize);

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
		unsigned int mStringSize = GetLength();
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
			charCpy(mString, str, totalLength + 1);
			delete[] str;
		}
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		unsigned int mStringSize = GetLength();
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
			charCpy(mString, str, totalLength + 1);
			delete[] str;
		}
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		unsigned int mStringSize = GetLength();
		char addChar = ' ';

		if (totalLength > mStringSize)
		{
			char* str = new char[totalLength + 1];
			unsigned int addCnt = totalLength - mStringSize;

			charCpy(str, mString, mStringSize);
			for (unsigned int i = mStringSize; i < totalLength; i++)
			{
				str[i] = addChar;
			}
			str[totalLength] = '\0';

			delete[] mString;
			mString = new char[totalLength + 1];
			charCpy(mString, str, totalLength + 1);
			delete[] str;
		}
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		unsigned int mStringSize = GetLength();
		char addChar = c;

		if (totalLength > mStringSize)
		{
			char* str = new char[totalLength + 1];
			unsigned int addCnt = totalLength - mStringSize;

			charCpy(str, mString, mStringSize);
			for (unsigned int i = mStringSize; i < totalLength; i++)
			{
				str[i] = addChar;
			}
			str[totalLength] = '\0';

			delete[] mString;
			mString = new char[totalLength + 1];
			charCpy(mString, str, totalLength + 1);
			delete[] str;
		}
	}

	void MyString::Reverse()
	{
		unsigned int mStringSize = GetLength();
		char tmp;

		for (unsigned int i = 0; i < mStringSize / 2; i++)
		{
			tmp = mString[i];
			mString[i] = mString[mStringSize - i - 1];
			mString[mStringSize - i - 1] = tmp;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		unsigned int mStringSize = GetLength();
		unsigned int rhsSize = rhs.GetLength();

		if (mStringSize == rhsSize)
		{
			for (unsigned int i = 0; i < mStringSize; i++)
			{
				if (mString[i] != rhs.mString[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		delete[] mString;
		mString = new char[rhs.mSize + 1];
		mSize = rhs.mSize;
		charCpy(mString, rhs.mString, mSize);
		 
		return *this;
	}

	// ASCII : Dec		Hex
	// A ~ Z : 65 ~ 90  0x41 ~ 0x5A
	// a ~ z : 97 ~ 122 0x61 ~ 0x7A
	// ( - ) : 32		0x20
	void MyString::ToLower()
	{
		unsigned int mStringSize = GetLength();

		for (unsigned int i = 0; i < mStringSize; i++)
		{
			if ((mString[i] >= 0x41) && (mString[i] <= 0x5A)) //대문자
			{
				mString[i] += 0x20;
			}
		}
	}

	void MyString::ToUpper()
	{
		unsigned int mStringSize = GetLength();

		for (unsigned int i = 0; i < mStringSize; i++)
		{
			if ((mString[i] >= 0x61) && (mString[i] <= 0x7A)) //소문자
			{
				mString[i] -= 0x20;
			}
		}
	}

	int MyString::myStrlen(const char* str)
	{
		int cnt = 0;
		if (str != nullptr)
		{
			while (str[cnt] != '\0')
			{
				cnt++;
			}
		}
		return cnt;
	}

	void MyString::charCpy(char* dst, const char* src, size_t srcSize)
	{
		if (dst != nullptr && src != nullptr)
		{
			for (size_t cnt = 0; cnt < srcSize; cnt++)
			{
				dst[cnt] = src[cnt];
			}
		}
	}

	char* MyString::subString(const char* src, int pos, int len)
	{
		int sSize = len - pos + 1;
		char* str = new char[len - pos + 2];

		for (int i = 0; i < len; i++)
		{
			str[i] = src[pos + i];
		}
		str[len] = '\0';
		return str;
	}

	bool MyString::strCmp(const char* str1, const char* str2)
	{
		int str1Size = myStrlen(str1);
		int str2Size = myStrlen(str2);
		if (str1Size == str2Size)
		{
			for (int i = 0; i < str1Size; i++)
			{
				if (str1[i] != str2[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}


}