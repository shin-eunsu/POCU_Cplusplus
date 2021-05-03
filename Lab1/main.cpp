#include <iostream>
#include "Add.h"

using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int result = 0;

	cout << "정수 2개 입력: ";
	cin >> a >> b;
	result = lab1::Add(a, b);
	cout << "Result : " << result << endl;

	return 0;
}

namespace lab1
{
	int Add(int a, int b)
	{
		return a + b;
	}
}