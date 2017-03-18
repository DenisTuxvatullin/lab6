#include "stdafx.h"
#include "CMyStringList.h"
#include <string>
#include <iostream>

CMyStringList::CMyStringList()
	:m_first(std::shared_ptr<CItem>()), m_last(std::shared_ptr<CItem>()), m_count(0)
{
}

CMyStringList::~CMyStringList()
{
	CMyStringList::Clear();
}

void CMyStringList::Clear()
{
	while (m_first)
	{
		Delete(m_first);
	}
	return;
}

CMyStringList& CMyStringList::operator=(const CMyStringList& val)
{
	m_first = std::make_shared<CItem>(*val.m_first);
	std::shared_ptr<CItem> curPointer = m_first;
	std::shared_ptr<CItem> oldPointer = val.GetFirst()->GetNext();
	for (int i = 1; i < m_count - 1; ++i)
	{
		auto newPointer = std::make_shared<CItem>(*oldPointer);
		newPointer->SetPrevious(curPointer);
		curPointer->SetNext(newPointer);
		curPointer = curPointer->GetNext();
		oldPointer = oldPointer->GetNext();
	}
	m_last = std::make_shared<CItem>(*val.m_last);
	curPointer->SetNext(m_last);
	m_last->SetPrevious(curPointer);
	return *this;
}

std::string CMyStringList::GetValue(const std::shared_ptr<CItem> &item) const
{
	return item->GetValue();
}

std::shared_ptr<CItem> CMyStringList::GetFirst() const
{
	return  m_first;
}

std::shared_ptr<CItem> CMyStringList::GetLast() const
{
	return m_last;
}

std::shared_ptr<CItem> CMyStringList::GetNext(const std::shared_ptr<CItem> &item) const
{
	return item->GetNext();
}

std::shared_ptr<CItem> CMyStringList::GetPrevious(const std::shared_ptr<CItem> &item) const
{
	return item->GetPrevious();
}

void CMyStringList::Delete(std::shared_ptr<CItem> &item)
{
	m_count--;
	auto it = item->GetNext();
	if (it)
	{
		item->GetNext()->SetPrevious(item->GetPrevious());
	}
	else
	{
		m_last = item->GetPrevious();
	}
	it = item->GetPrevious();

	if (it)
	{
		item->GetPrevious()->SetNext(item->GetNext());
	}
	else
	{
		m_first = item->GetNext();
	}
	item.reset();
}

void CMyStringList::Insert(std::string str, const std::shared_ptr<CItem> &item)
{
	m_count++;
	auto newItem = std::make_shared<CItem>(move(str));
	if (!m_first)
	{
		m_first = newItem;
		m_last = newItem;
		return;
	}
	if (item)
	{
		newItem->SetPrevious(item);
		auto next = item->GetNext();
		newItem->SetNext(next);

		if (next)
		{
			next->SetPrevious(newItem);
		}

		item->SetNext(newItem);
		if (m_last == item)
		{
			m_last = newItem;
		}
	}
	else
	{
		newItem->SetPrevious(m_last);
		m_last->SetNext(newItem);
		m_last = newItem;
	}
}

void CMyStringList::Info()
{
	std::cout << "MyStringList contains: ";
	std::shared_ptr<CItem> curPointer = GetFirst();
	std::cout << curPointer->GetValue() << " ";
	while (curPointer->GetNext())
	{
		curPointer = curPointer->GetNext();
		std::cout << curPointer->GetValue() << " ";
	}
		
}