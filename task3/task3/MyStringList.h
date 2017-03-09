#pragma once
#include "Item.h"
#include <memory>

class CMyStringList
{
public:
	CMyStringList::CMyStringList();
	CMyStringList(const CMyStringList &val);
	CMyStringList & operator=(const CMyStringList& val);
	std::string GetValue(const std::shared_ptr<CItem> &item) const;
	std::shared_ptr<CItem> GetFirst() const;
	std::shared_ptr<CItem> GetLast() const;
	std::shared_ptr<CItem> GetNext(const std::shared_ptr<CItem> &item) const;
	std::shared_ptr<CItem> GetPrevious(const std::shared_ptr<CItem> &item) const;
	void Delete(std::shared_ptr<CItem> &item);
	void Insert(std::string str, const std::shared_ptr<CItem> &item = std::shared_ptr<CItem>());
private:
	std::shared_ptr<CItem> m_first, m_last;
	int m_count;
};