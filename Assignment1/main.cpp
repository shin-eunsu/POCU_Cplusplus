#include "Mystring.h"

using namespace assignment1;

int main()
{
	MyString s("Hello");
	MyString s2("Helloello");

	s.Append("elld");
	bool b = (s == s2);
}