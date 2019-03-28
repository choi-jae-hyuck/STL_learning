#pragma once
#include <iostream>



class String {
	int num{ 0 };
	char * word{ nullptr };
public:
	String() = default;

	String(int n);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	void set(int n);

	int getNum() const;
	void getP() const;

	friend std::ostream& operator<<(std::ostream&, const String&);
};