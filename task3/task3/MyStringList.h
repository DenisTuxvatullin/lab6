#pragma once
#include "Item.h"
#include <algorithm>

class CMyStringList
{
public:
	CMyStringList::CMyStringList()
		:m_first(shared_ptr<CItem>()), m_last(shared_ptr<CItem>())
	{
	}

	void swap(CMyStringList& other)
	{
		m_first.swap(other.m_first);
		m_last.swap(other.m_last);
	}

	CMyStringList(const CMyStringList& other) 
		: m_first(other.m_first), // конструктор копирования из lvalue
		  m_last(other.m_last)
	{
	}

	CMyStringList(CMyStringList&& other) // конструктор копирования из rvalue, он же конструктор переноса
	{
		this->swap(other);
	}

	CMyStringList& operator=(CMyStringList other) // оператор присваивания
	{                     // передача параметра по значению важна!
		this->swap(other);      // обмен с временной копией
		return *this;
	}
	string GetValue(const std::shared_ptr<CItem> &item) const;
	shared_ptr<CItem> GetFirst() const;
	shared_ptr<CItem> GetLast() const;
	shared_ptr<CItem> GetNext(const shared_ptr<CItem> &item) const;
	shared_ptr<CItem> GetPrevious(const shared_ptr<CItem> &item) const;
	void Delete(const shared_ptr<CItem> &item);
	void Insert(const string str, const shared_ptr<CItem> &item = shared_ptr<CItem>());
	
private:
	shared_ptr<CItem> m_first, m_last;
};





string CMyStringList::GetValue(const shared_ptr<CItem> &item) const
{
	return item->GetValue();
}

shared_ptr<CItem> CMyStringList::GetFirst() const
{
	return m_first;
}

shared_ptr<CItem> CMyStringList::GetLast() const
{
	return m_last;
}

shared_ptr<CItem> CMyStringList::GetNext(const shared_ptr<CItem> &item) const
{
	return item->GetNext();
}

shared_ptr<CItem> CMyStringList::GetPrevious(const shared_ptr<CItem> &item) const
{
	return item->GetPrevious();
}



void CMyStringList::Delete(const shared_ptr<CItem> &item)
{
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
}

void CMyStringList::Insert(const string str, const shared_ptr<CItem> &item)
{

	auto newItem = make_shared<CItem>(move(str));
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