#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

namespace lab2
{
	int GetStreamSize(std::istream& in);

	// in: ���⼭ ����� �Է��� ��������. cin���� �д� �� �ƴմϴ�.
	// out: ���⿡ ����� ������. cout�� ���� �� �ƴմϴ�.
	void PrintIntegers(std::istream& in, std::ostream& out);
	void PrintMaxFloat(std::istream& in, std::ostream& out);
}