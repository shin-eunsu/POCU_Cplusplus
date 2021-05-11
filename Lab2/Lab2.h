#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

namespace lab2
{
	// in: 여기서 사용자 입력을 읽으세요. cin에서 읽는 게 아닙니다.
	// out: 여기에 출력을 쓰세요. cout에 쓰는 게 아닙니다.
	void PrintIntegers(std::istream& in, std::ostream& out);
	void PrintMaxFloat(std::istream& in, std::ostream& out);

	bool IsInteger(const char c);
	bool IsFloat(const char c);
	float GetMaxVal(float val[], int cnt);
	char* ReSize(char* str, int newSize);
}