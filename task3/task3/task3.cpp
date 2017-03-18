// task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CMyStringList.h"
#include <cassert>
#include <stdlib.h>  

int _tmain(int argc, _TCHAR* argv[])
{
	
		CMyStringList testOverflow;
		for (int i = 0; i < 100; ++i)
		{
			testOverflow.Insert("Hello");
		}
	

	CMyStringList lst1;
	lst1.Insert("Hello");
	lst1.Insert("Goodbye");
	CMyStringList lst2;
	lst2 = lst1;
	assert(lst1.GetLast()->GetValue() == "Goodbye");
	assert(!lst1.GetLast()->GetNext());
	lst2.Insert("Test");
	assert(lst1.GetLast()->GetValue() == "Goodbye");
	assert(!lst1.GetLast()->GetNext());
	lst1.Info();
	system("pause");
	return 0;
}

