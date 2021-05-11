#include "Lab2.h"

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
		out << setw(13) << setfill('-') << " " << setw(11) << " " << setw(8) << "-" << setfill(' ') << endl;

		int strSize = BUFSIZ;
		int charCnt = 0;
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
					char* tmpStr = new char[strSize];
					memcpy_s(tmpStr, strSize, str, strlen(str));
					delete[] str;
					str = new char[strSize];
					memcpy_s(str, strSize, tmpStr, strSize);
					delete[] tmpStr;
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
		int charCnt = 0;
		int arrayCnt = 0;
		int strSize = BUFSIZ;
		char* str = new char[BUFSIZ];
		float inputArray[BUFSIZ];
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
					char* tmpStr = new char[strSize];
					memcpy_s(tmpStr, strSize, str, strlen(str));
					delete[] str;
					str = new char[strSize];
					memcpy_s(str, strSize, tmpStr, strSize);
					delete[] tmpStr;
				}
			}
			else if (bCheckPrint)
			{
				str[charCnt] = '\0';
				float outVal = atof(str);
				inputArray[arrayCnt++] = outVal;

				out << setw(5) << " " << setw(15) << internal << showpos << fixed << setprecision(3) << outVal << endl;

				charCnt = 0;
				memset(str, '\0', BUFSIZ);
				bCheckPrint = false;
			}
		}
		if (charCnt != 0)
		{
			str[charCnt] = '\0';
			float outVal = atof(str);
			inputArray[arrayCnt++] = outVal;

			out << setw(5) << " " << setw(15) << internal << showpos << fixed << setprecision(3) << outVal << endl;
		}

		out << "max: " << setw(15) << internal << showpos << fixed << setprecision(3) << GetMaxVal(inputArray, arrayCnt) << endl;
		delete[] str;
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

	int ReSize(char** array)
	{
		int reSize = strlen(*array) * 2;
		char* tmpStr = new char[reSize];
		memcpy_s(tmpStr, reSize, *array, strlen(*array));
		delete[] *array;
		*array = new char[reSize];
		memcpy_s(*array, reSize, tmpStr, reSize);
		delete[] tmpStr;

		return reSize;
	}
}