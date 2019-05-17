#pragma once
#include <iostream>
#include <iterator>
using namespace std::rel_ops;

//5. 이동 생성자
//6. 이동할당 연산자
//7. (2019.05.17) 역방향 반복자를 제공

class Iter;					//forward declaration
class RevIter;

class String {
	int num{ 0 };
	char * word{ nullptr };
public:
	String() = default;

	String(int n);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	String(String&& other);
	String& operator=(String&& other);

	void set(int n);

	int getNum() const;
	char* getP() const;

	friend std::ostream& operator<<(std::ostream&, const String&);
	
	bool operator==(const String& rhs);
	bool operator<(const String& rhs) const;

	Iter begin();
	Iter end();
	
	RevIter rbegin();
	RevIter rend();
};

class Iter : public std::iterator<std::random_access_iterator_tag, char> {
	iterator::pointer word;
public:
	Iter(iterator::pointer word) : word{ word } {}

	iterator::difference_type operator-(const Iter& other) const {
		return word - other.word;
	}
	Iter operator+(iterator::difference_type n) const {
		return Iter(word + n);
	}
	Iter operator-(iterator::difference_type n) const {
		return Iter(word - n);
	}

	//논리연산		<, <=, >, >=, ==, !=
	bool operator<(const Iter& other) const {
		return word < other.word;
	}
	bool operator==(const Iter& other) const {
		return word == other.word;
	}
	bool operator!=(const Iter& other) const {
		return word != other.word;
	}

	iterator::value_type operator*() const{
		return *word;
	}
	iterator::value_type operator*() {
		return *word;
	}
	Iter& operator++() {
		++word;
		return *this;
	}
	Iter operator++(int) {
		Iter temp{ *this };
		++(*this);
		return temp;
	}
	Iter& operator--() {
		--word;
		return *this;
	}
	Iter operator--(int) {
		Iter temp{ *this };
		--(*this);
		return temp;
	}
};

class RevIter {
	char *word;
public:
	RevIter(char* word) : word{ word } {}

	RevIter& operator++() {				//pre-increment
		--word;
		return *this;
	}
	RevIter& operator++(int) {			//post-increment
		RevIter temp{ *this };
		++(*this);
		return temp;
	}

	char& operator*() {					//write-mode
		return *(word-1);
	}
	char operator*() const {			//read-mode
		return *(word-1);
	}

	bool operator!=(const RevIter& other)  const {
		return word != other.word;
	}
};