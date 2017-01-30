#pragma once
#include "Item.h"
using namespace std;

class CMyStringList
{
public:
	CMyStringList();
	~CMyStringList();
	string GetValue(const std::shared_ptr<CItem> &item) const;
	shared_ptr<CItem> GetFirst() const;
	shared_ptr<CItem> GetLast() const;
	shared_ptr<CItem> GetNext(const shared_ptr<CItem> &item) const;
	shared_ptr<CItem> GetPrevious(const shared_ptr<CItem> &item) const;
	void Delete(const shared_ptr<CItem> &item);
	void Insert(const string str, const shared_ptr<CItem> &item = shared_ptr<CItem>())
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
			newItem->SetNext(shared_ptr<CItem>());
			m_last->SetNext(newItem);
			m_last = newItem;
		}
	}
private:
	shared_ptr<CItem> m_first;
	shared_ptr<CItem> m_last;
};

CMyStringList::CMyStringList()
	:m_first(), m_last()
{}

CMyStringList::~CMyStringList()
{}

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