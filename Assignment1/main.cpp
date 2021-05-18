#include "Mystring.h"

using namespace assignment1;

int main()
{
	MyString s("Halo");
	MyString s2(" s2");

	//s.Append(" append");
	s.GetCString();
	MyString s3 = s + s2;

	//s.Interleave("123456");

	//s.RemoveAt(1);

	//bool b = (s == s2);


	//s2.IndexOf("o");
	//s2.LastIndexOf("o");

	//s.RemoveAt(0);
	//s.RemoveAt(2);
	//s.RemoveAt(4);

	s.PadLeft(2);
	s.PadLeft(8);

	//s.PadRight(2);
	//s.PadRight(8);


	//s.Reverse();
	//s.ToLower();
	//s.ToUpper();
}