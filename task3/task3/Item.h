#pragma once
#include <string>
#include <memory>
using namespace std;

class CItem
{
public:
	CItem(string value);
	~CItem();
	string GetValue() const;
	void SetValue(string value);
	void SetNext(const shared_ptr<CItem> &next);
	void SetPrevious(const shared_ptr<CItem> &previous);
	shared_ptr<CItem> GetNext() const;
	shared_ptr<CItem> GetPrevious() const;
private:
	string m_value;
	shared_ptr<CItem>  m_previous;
	weak_ptr<CItem> m_next;
};

CItem::CItem(string value)
	:m_value(move(value)),
	m_previous(std::shared_ptr<CItem>()),
	m_next(std::weak_ptr<CItem>())
{}

CItem::~CItem()
{}

string CItem::GetValue() const
{
	return m_value;
}

void CItem::SetValue(string value)
{
	m_value = move(value);
}

void CItem::SetNext(const shared_ptr<CItem> &next)
{
	m_next = next;
}

void CItem::SetPrevious(const shared_ptr<CItem> &previous)
{
	m_previous = previous;
}

shared_ptr<CItem> CItem::GetNext() const
{
	return m_next.lock();
}

shared_ptr<CItem> CItem::GetPrevious() const
{
	return m_previous;
}