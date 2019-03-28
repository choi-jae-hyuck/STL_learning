#include "String.h"
#include <random>

std::default_random_engine dre;
std::uniform_int_distribution<> uid('a', 'z');

String::String(int n) :num{ n } {
	word = new char[num];
	for (int i = 0; i < num; ++i)
	{
		word[i] = uid(dre);
	}
}
String::String(const String& other) : num{ other.num } {
	word = new char[num];
	memcpy(word, other.word, num);
}
String& String::operator=(const String& other) {
		if (this == &other) //자기자신을 복사하는것 제외
			return *this;
		delete[] word;
		num = other.num;
		word = new char[num];
		memcpy(word, other.word, num);
	}
String::~String() {
	delete[] word;
}

void String::set(int n) {
	num = n;
	if (!word)
		delete[] word;
	word = new char[num];
	for (int i = 0; i < num; ++i)
		word[i] = uid(dre);
}

int String::getNum() const {
	return num;
}

char* String::getP() const{
	return word;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	for (int i = 0; i < str.num; ++i)
		os << str.word[i];
	return os;
}
