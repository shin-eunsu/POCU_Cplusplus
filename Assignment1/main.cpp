#include "Mystring.h"

using namespace assignment1;

int main()
{
	MyString s("Hello");
	MyString s2("Helloello");

	s.Append(" world");
	//bool b = (s == s2);

	MyString s3 = s + s2;

	s2.IndexOf("o");
	s2.LastIndexOf("o");
}