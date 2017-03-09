// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task3/MyStringList.h"
#include "../task3/Item.h"

BOOST_AUTO_TEST_CASE(TestItem)
{
	auto item1 = std::make_shared<CItem>("car");
	auto item2 = std::make_shared<CItem>("bike");
	auto item3 = std::make_shared<CItem>("plane");

	item1->SetNext(item2);
	item1->SetPrevious(item3);
	BOOST_CHECK_EQUAL(item1->GetValue(), "car");
	BOOST_CHECK_EQUAL(item2->GetValue(), "bike");
	BOOST_CHECK_EQUAL(item3->GetValue(), "plane");

	item1->SetValue("boat");
	BOOST_CHECK_EQUAL(item1->GetValue(), "boat");

	BOOST_CHECK_EQUAL(item1->GetNext(), item2);
	BOOST_CHECK_EQUAL(item1->GetPrevious(), item3);
	BOOST_CHECK_EQUAL(item2->GetNext(), std::shared_ptr<CItem>());
	BOOST_CHECK_EQUAL(item2->GetPrevious(), std::shared_ptr<CItem>());
	BOOST_CHECK_EQUAL(item3->GetNext(), std::shared_ptr<CItem>());
	BOOST_CHECK_EQUAL(item3->GetPrevious(), std::shared_ptr<CItem>());
}


BOOST_AUTO_TEST_CASE(CanReturnLinkToFirstAndLastItemsAndInsertToEnd)
{	
	CMyStringList list;
	list.Insert("car");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "car");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "car");

	list.Insert("bike");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "car");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "bike");
}

BOOST_AUTO_TEST_CASE(CanInsertAfterIterator)
{
	CMyStringList list;
	list.Insert("car");
	list.Insert("bike");

	auto it = list.GetLast()->GetPrevious();
	list.Insert("boat", it);
	BOOST_CHECK_EQUAL(list.GetLast()->GetPrevious()->GetValue(), "boat");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "bike");
}

BOOST_AUTO_TEST_CASE(CanDeleteItem)
{
	CMyStringList list;
	{
		list.Insert("car");
		list.Insert("bike");
		list.Insert("boat");
		
		list.Delete(list.GetLast());
		BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "bike");

		list.Delete(list.GetFirst());
		BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "bike");
		BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "bike");

		list.Delete(list.GetFirst());
		BOOST_CHECK_EQUAL(list.GetLast(), std::shared_ptr<CItem>());
		BOOST_CHECK_EQUAL(list.GetFirst(), std::shared_ptr<CItem>());
	}
}
