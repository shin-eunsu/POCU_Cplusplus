#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
	{
		int len = strlen(name) + 1;
		strcpy_s(mName, len, name);
	}

	Person::Person(const Person& other)
		: mWeight(other.mWeight)
	{
		int len = strlen(other.mName) + 1;
		mName = new char[len];
		strcpy_s(mName, len, other.mName);
	}

	Person::~Person()
	{
		delete[] mName;
	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}