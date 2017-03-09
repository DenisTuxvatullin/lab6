#pragma once
#include <string>
#include <memory>

class CItem
{
public:
	CItem(std::string value);
	CItem(const CItem &val);
	std::string GetValue() const;
	void SetValue(std::string value);
	void SetNext(const std::shared_ptr<CItem> &next);
	void SetPrevious(const std::shared_ptr<CItem> &previous);
	std::shared_ptr<CItem> GetNext() const;
	std::shared_ptr<CItem> GetPrevious() const;
	
private:
	std::string m_value;
	std::shared_ptr<CItem>  m_previous;
	std::weak_ptr<CItem> m_next;
};