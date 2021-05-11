#include "Lab2.h"
#include <iostream>
#include <crtdbg.h>

#if _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int main()
{
	lab2::PrintIntegers(cin, cout);
	lab2::PrintMaxFloat(cin, cout);
	_CrtDumpMemoryLeaks();

	return 0;
}