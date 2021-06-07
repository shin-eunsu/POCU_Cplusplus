#include <cassert>
#include "Lab6.h"

int Test0(void);
int Test_F(void);

int main()
{
	//Test0();
	Test_F();
}

int Test0(void)
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(4);
	v.push_back(12);
	v.push_back(7);
	v.push_back(11);

	int sum = lab6::Sum(v);
	int max = lab6::Max(v);
	int min = lab6::Min(v);
	float average = lab6::Average(v);
	int numWithMaxOccurence = lab6::NumberWithMaxOccurrence(v);
	lab6::SortDescending(v);

	assert(sum == 41);
	assert(max == 12);
	assert(min == 3);
	assert(average == 6.83333349f);
	assert(numWithMaxOccurence == 4);

	for (int i = 0; i < (int)v.size() - 1; ++i)
	{
		assert(v[i] >= v[i + 1]);
	}

	return 0;
}

int Test_F(void)
{
	std::vector<int> v0;
	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(2);
	v0.push_back(3);

	int numWithMaxOccurence = lab6::NumberWithMaxOccurrence(v0);
	assert(numWithMaxOccurence == 2);

	std::vector<int> v1;
	v1.push_back(-2);
	v1.push_back(-2);
	v1.push_back(-3);
	v1.push_back(-2);
	v1.push_back(-4);
	v1.push_back(-6);
	v1.push_back(-4);
	v1.push_back(-4);
	v1.push_back(-4);
	int numWithMaxOccurence1 = lab6::NumberWithMaxOccurrence(v1);
	assert(numWithMaxOccurence1 == -4);


	std::vector<int> v2;
	v2.push_back(-1);
	v2.push_back(-14);
	v2.push_back(-1);
	v2.push_back(-2);
	v2.push_back(3);
	v2.push_back(-2);
	v2.push_back(7);
	v2.push_back(-4);
	v2.push_back(-6);
	v2.push_back(4);
	v2.push_back(-4);
	v2.push_back(-4);
	v2.push_back(-9);
	int numWithMaxOccurence2 = lab6::NumberWithMaxOccurrence(v2);
	assert(numWithMaxOccurence2 == -4);


	return 0;
}

