#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		Person(const Person& other);
		~Person();
		
		Person operator=(const Person& rhs);
		const std::string& GetName() const;
		unsigned int GetWeight() const;

	private:
		std::string mName;
		unsigned int mWeight;
	};
}