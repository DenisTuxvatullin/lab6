// task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyStringList.h"
#include <cassert>


int _tmain(int argc, _TCHAR* argv[])
{
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
	return 0;
}

