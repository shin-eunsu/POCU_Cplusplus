#include "Lab2.h"

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int num;
		string trash;

		out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
		out << setw(13) << setfill('-') << " " << setw(11) << " " << setw(8) << "-" << setfill(' ') << endl;

		while (!in.eof())
		{
			in >> num;

			if (in.fail())
			{
				in.clear();
				in >> trash;
			}
			else
			{
				out << setw(12) << oct << num << setw(11) << dec << num << setw(9) << hex << uppercase << num << endl;
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float num;
		float maxNum;
		string trash;
		int cnt = 0;

		while (!in.eof())
		{
			in >> num;

			if (in.fail())
			{
				in.clear();
				in >> trash;
			}
			else
			{
				if (cnt == 0)
				{
					maxNum = num;
				}
				else
				{
					if (num > maxNum)
					{
						maxNum = num;
					}
				}
				out << setw(5) << " " << setw(15) << internal << showpos << fixed << setprecision(3) << num << endl;
			}
		}
		out << "max: " << setw(15) << internal << showpos << fixed << setprecision(3) << maxNum << endl;
	}


	/// <summary>
	/// TEST 2
	/// </summary>
	/// <param name="in"></param>
	/// <param name="out"></param>
	void PrintIntegers2(std::istream& in, std::ostream& out)
	{
		out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
		out << setw(13) << setfill('-') << " " << setw(11) << " " << setw(8) << "-" << setfill(' ') << endl;

		unsigned long int charCnt = 0;
		unsigned long int inputArrayCnt = 0;
		unsigned long int strSize = 512;
		unsigned long int inputArraySize = 512;
		char* str = new char[strSize];
		int* inputArray = new int[inputArraySize];
		char c;

		while (true)
		{
			if (in.get(c))
			{
				if (IsInteger(c))
				{
					str[charCnt++] = c;
					checkCharResize(str, strSize, charCnt);
				}
				else
				{
					str[charCnt] = '\0';

					if (strlen(str) > 0)
					{
						inputArray[inputArrayCnt++] = atoi(str);
						inputArray = checkArrayResize(inputArray, inputArraySize, inputArrayCnt);
					}
					charCnt = 0;
					memset(str, '\0', strSize);
				}
			}

			if (in.eof())
			{
				str[charCnt] = '\0';
				if (strlen(str) > 0)
				{
					inputArray[inputArrayCnt++] = atoi(str);
				}
				break;
			}
		}

		for (unsigned long int i = 0; i < inputArrayCnt; i++)
		{
			out << setw(12) << oct << inputArray[i] << setw(11) << dec << inputArray[i] << setw(9) << hex << uppercase << inputArray[i] << endl;
		}

		delete[] str;
		delete[] inputArray;
	}

	void PrintMaxFloat2(std::istream& in, std::ostream& out)
	{
		unsigned long int charCnt = 0;
		unsigned long int inputArrayCnt = 0;
		unsigned long int strSize = 512;
		unsigned long int inputArraySize = 512;
		char* str = new char[strSize];
		float* inputArray = new float[inputArraySize];
		char c;

		while (true)
		{
			if (in.get(c))
			{
				if (IsFloat(c))
				{
					str[charCnt++] = c;
					checkCharResize(str, strSize, charCnt);
				}
				else
				{
					str[charCnt] = '\0';
					if (strlen(str) > 0)
					{
						inputArray[inputArrayCnt++] = strtof(str, NULL);
						inputArray = checkArrayResize(inputArray, inputArraySize, inputArrayCnt);
					}

					charCnt = 0;
					memset(str, '\0', strSize);
				}
			}

			if (in.eof())
			{
				str[charCnt] = '\0';
				if (strlen(str) > 0)
				{
					inputArray[inputArrayCnt++] = strtof(str, NULL);
				}
				break;
			}
		}

		for (unsigned long int i = 0; i < inputArrayCnt; i++)
		{
			out << setw(5) << " " << setw(15) << internal << showpos << fixed << setprecision(3) << inputArray[i] << endl;
		}
		if (inputArrayCnt > 0)
		{
			out << "max: " << setw(15) << internal << showpos << fixed << setprecision(3) << GetMaxVal(inputArray, inputArrayCnt) << endl;
		}

		delete[] str;
		delete[] inputArray;
	}


	/// <summary>
	/// TEST 1
	/// </summary>
	/// <param name="in"></param>
	/// <param name="out"></param>
	void PrintIntegers1(std::istream& in, std::ostream& out)
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

	void PrintMaxFloat1(std::istream& in, std::ostream& out)
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
		int newMemSize = sizeof(str) * (newSize);
		int srcMemSize = sizeof(str) * (newSize / 2);

		char* tmpStr = new char[newSize];
		memcpy_s(tmpStr, newMemSize, str, srcMemSize);
		delete[] str;
		str = new char[newSize];
		memcpy_s(tmpStr, newMemSize, str, srcMemSize);
		delete[] tmpStr;

		return str;
	}

	float* ReSize(float* val, int newSize)
	{
		int newMemSize = sizeof(val) * (newSize);
		int srcMemSize = sizeof(val) * (newSize / 2);

		float* tmpVal = new float[newSize];
		memcpy_s(tmpVal, newMemSize, val, srcMemSize);
		delete[] val;
		val = new float[newSize];
		memcpy_s(val, newMemSize, tmpVal, srcMemSize);
		delete[] tmpVal;

		return val;
	}

	int* ReSize(int* val, int newSize)
	{
		int newMemSize = sizeof(val) * (newSize);
		int srcMemSize = sizeof(val) * (newSize / 2);

		int* tmpVal = new int[newSize];
		memcpy_s(tmpVal, newMemSize, val, srcMemSize);
		delete[] val;
		val = new int[newSize];
		memcpy_s(val, newMemSize, tmpVal, srcMemSize);
		delete[] tmpVal;

		return val;
	}

	char* checkCharResize(char* str, unsigned long int& strSize, const unsigned long int charCnt)
	{
		if (charCnt >= strSize)
		{
			strSize = strSize * 2;
			str = ReSize(str, strSize);
		}
		return str;
	}

	int* checkArrayResize(int* inputArray, unsigned long int& inputArraySize, const unsigned long int inputArrayCnt)
	{
		if (inputArrayCnt >= inputArraySize)
		{
			inputArraySize *= 2;
			inputArray = ReSize(inputArray, inputArraySize);
		}
		return inputArray;
	}

	float* checkArrayResize(float* inputArray, unsigned long int& inputArraySize, const unsigned long int inputArrayCnt)
	{
		if (inputArrayCnt >= inputArraySize)
		{
			inputArraySize *= 2;
			inputArray = ReSize(inputArray, inputArraySize);
		}
		return inputArray;
	}
}