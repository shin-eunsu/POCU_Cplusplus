#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
	{
		mName = name;
	}

	Person::Person(const Person& other)
		: mWeight(other.mWeight)
	{
		mName = other.mName;
	}

	Person::~Person()
	{
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