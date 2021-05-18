#include "Mystring.h"

using namespace assignment1;

int main()
{
	MyString s("Hel123 lo");
	MyString s2("Hell123oel lo");

	s.Append("ello");
	bool b = (s == s2);

	//MyString s3 = s + s2;

	//s2.IndexOf("o");
	//s2.LastIndexOf("o");

	//s.RemoveAt(0);
	//s.RemoveAt(2);
	//s.RemoveAt(4);

	//s.PadRight(2);
	//s.PadRight(8);
	//s.PadRight(11);

	//s.Reverse();
	s.ToLower();
	s2.ToUpper();

	system("pause");
}