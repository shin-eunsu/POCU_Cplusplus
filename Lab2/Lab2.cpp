#include "Lab2.h"

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
		out << setw(13) << setfill('-') << " " << setw(11) << " " << setw(8) << "-" << setfill(' ') << endl;

		unsigned long int strSize = BUFSIZ;
		unsigned long int charCnt = 0;
		char* str = new char[BUFSIZ];
		bool bCheckPrint = false;
		char c;
		while (in.get(c))
		{
			if (IsInteger(c))
			{
				str[charCnt++] = c;
				bCheckPrint = true;

				if (charCnt >= strSize)
				{
					strSize = strSize * 2;
					str = ReSize(str, strSize);
				}
			}
			else if (bCheckPrint)
			{
				str[charCnt] = '\0';
				int outValue = atoi(str);
				out << setw(12) << oct << outValue << setw(11) << dec << outValue << setw(9) << hex << uppercase << outValue << endl;

				charCnt = 0;
				memset(str, '\0', strSize);
				bCheckPrint = false;
			}
		}
		if (charCnt != 0)
		{
			str[charCnt] = '\0';
			int outValue = atoi(str);
			out << setw(12) << oct << outValue << setw(11) << dec << outValue << setw(9) << hex << uppercase << outValue << endl;
		}
		delete[] str;
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		unsigned long int charCnt = 0;
		unsigned long int arrayCnt = 0;
		unsigned long int strSize = BUFSIZ;
		unsigned long int arrSize = BUFSIZ;
		char* str = new char[BUFSIZ];
		float* inputArray = new float[BUFSIZ];
		bool bCheckPrint = false;
		char c;

		while (in.get(c))
		{
			if (IsFloat(c))
			{
				str[charCnt++] = c;
				bCheckPrint = true;

				if (charCnt >= strSize)
				{
					strSize = strSize * 2;
					str = ReSize(str, strSize);
				}
			}
			else if (bCheckPrint)
			{
				str[charCnt] = '\0';
				float outVal = strtof(str, NULL);
				inputArray[arrayCnt++] = outVal;

				if (arrayCnt >= arrSize)
				{
					arrSize = arrSize * 2;
					inputArray = ReSize(inputArray, arrSize);
				}

				out << setw(5) << " " << setw(15) << internal << showpos << fixed << setprecision(3) << outVal << endl;

				charCnt = 0;
				memset(str, '\0', strSize);
				bCheckPrint = false;
			}
		}
		if (charCnt != 0)
		{
			str[charCnt] = '\0';
			float outVal = strtof(str, NULL);
			inputArray[arrayCnt++] = outVal;

			out << setw(5) << " " << setw(15) << internal << showpos << fixed << setprecision(3) << outVal << endl;
		}

		out << "max: " << setw(15) << internal << showpos << fixed << setprecision(3) << GetMaxVal(inputArray, arrayCnt) << endl;
		delete[] str;
		delete[] inputArray;
	}

	bool IsInteger(const char c)
	{
		int val = static_cast<int>(c);
		if ((val >= 48 && val <= 57) || val == 45)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsFloat(const char c)
	{
		bool bReturnVal = false;
		bool bDot = false;
		int val = static_cast<int>(c);

		if ((val >= 48 && val <= 57) || val == 46 || val == 45)
		{
			return true;
		}
		else
		{
			return false;
		}
		return bReturnVal;
	}

	float GetMaxVal(float val[], int cnt)
	{
		float returnVal = val[0];

		for (int i = 0; i < cnt; i++)
		{
			if (returnVal < val[i])
				returnVal = val[i];
		}
		return returnVal;
	}

	char* ReSize(char* str, int newSize)
	{
		char* tmpStr = new char[newSize];
		memcpy_s(tmpStr, newSize, str, strlen(str));
		delete[] str;
		str = new char[newSize];
		memcpy_s(str, newSize, tmpStr, newSize);
		delete[] tmpStr;

		return str;
	}

	float* ReSize(float* val, int newSize)
	{
		float* tmpVal = new float[newSize];
		memcpy_s(tmpVal, newSize, val, sizeof(val));
		delete[] val;
		val = new float[newSize];
		memcpy_s(val, newSize, tmpVal, newSize);
		delete[] tmpVal;

		return val;
	}
}