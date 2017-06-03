#pragma once

#include <climits>
#include <cassert>

class String {
	char* data_;

	void copy(const String&);
	void destroy();
public:
	String();
	String(char* data);
	String& operator=(const String&);
	~String();

	char at(size_t idx) const;//връща елемент на позиция
	size_t size() const;

	char& operator[](size_t idx);
	const char operator[](size_t idx) const;

	String& operator+=(const String& rhs);
	bool operator<(const String& rhs);
	bool operator>(const String& rhs);
	bool operator<=(const String& rhs);
	bool operator>=(const String& rhs);

	bool operator==(const String& rhs);
	bool operator!=(const String& rhs);

	friend String operator+ (const String& lhs, const String& rhs);
	friend ostream& operator<<(ostream& os, const String& obj);
	friend istream& operator>>(istream& is, String& obj);
};