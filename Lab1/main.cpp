#include <iostream>
#include "Add.h"

using namespace std;
using namespace lab1;

int main()
{
	int a = 0;
	int b = 0;
	int result = 0;

	cout << "input two numbers : ";
	cin >> a >> b;
	result = Add(a, b);
	cout << "Result : " << result << endl;

	return 0;
}