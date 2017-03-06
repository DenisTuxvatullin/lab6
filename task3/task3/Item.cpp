#include "stdafx.h"
#include "Item.h"

CItem::CItem(const CItem &val) :
m_previous(std::shared_ptr<CItem>()),
m_next(std::weak_ptr<CItem>()),
m_value(move(val.m_value))
{
}

CItem::CItem(std::string value)
	:m_value(move(value)),
	m_previous(std::shared_ptr<CItem>()),
	m_next(std::weak_ptr<CItem>())
{
}


std::string CItem::GetValue() const
{
	return m_value;
}

void CItem::SetValue(std::string value)
{
	m_value = move(value);
}

void CItem::SetNext(const std::shared_ptr<CItem> &next)
{
	m_next = next;
}

void CItem::SetPrevious(const std::shared_ptr<CItem> &previous)
{
	m_previous = previous;
}

std::shared_ptr<CItem> CItem::GetNext() const
{
	return m_next.lock();
}

std::shared_ptr<CItem> CItem::GetPrevious() const
{
	return m_previous;
}