#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

namespace lab2
{
	// in: ���⼭ ����� �Է��� ��������. cin���� �д� �� �ƴմϴ�.
	// out: ���⿡ ����� ������. cout�� ���� �� �ƴմϴ�.
	void PrintIntegers(std::istream& in, std::ostream& out);
	void PrintMaxFloat(std::istream& in, std::ostream& out);

	bool IsInteger(const char c);
	bool IsFloat(const char c);
	float GetMaxVal(float val[], int cnt);
	char* ReSize(char* str, int newSize);
}