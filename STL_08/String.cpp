#include "String.h"
#include <random>

std::default_random_engine dre;
std::uniform_int_distribution<> uid('a', 'z');

String::String(int n) :num{ n } {
	word = new char[num];
	for (int i = 0; i < num; ++i)
		word[i] = uid(dre);
	std::cout << "String(int) 생성, 자신 :" << this << ", HEAP : " << (void*)word << std::endl;
}
String::String(const String& other) : num{ other.num } {
	word = new char[num];
	memcpy(word, other.word, num);

	std::cout << this << "를 복사생성함, 원본 : " << &other << ", HEAP : " << (void*)word << std::endl;
}
String& String::operator=(const String& other) {
		if (this == &other) //자기자신을 복사하는것 제외
			return *this;
		delete[] word;
		num = other.num;
		word = new char[num];
		memcpy(word, other.word, num);

		std::cout << "할당연산자" << std::endl;
}
String::~String() {
	delete[] word;
	std::cout << "소멸 : " << this << ", HEAP : " << (void*)word << std::endl;
}

String::String(String&& other) :num{ other.num }, word{other.word} {
	other.num = 0;
	other.word = nullptr;
	word = other.word;
	std::cout << this << "를 이동생성함, 원본 : " << &other << ", HEAP : " << (void*)word << std::endl;
}

String& String::operator=(String&& other) {
	if (this == &other)
		return *this;
	delete[] word;
	num = other.num;
	word = other.word;
	other.num = 0;
	other.word = nullptr;
	std::cout << "이동할당연산자" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const String& str){
	for (int i = 0; i < str.num; ++i)
		os << str.word[i];
	return os;
}

bool String::operator==(const String& rhs) {
	if (num == rhs.num)
		return true;
	return false;
}
bool String::operator<(const String& rhs) const {
	return num < rhs.num;
}

Iter String::begin() {
	return Iter(word);
}
Iter String::end() {
	return Iter(word + num);
}

RevIter String::rbegin() {
	return RevIter(word + num);
}
RevIter String::rend() {
	return RevIter(word);
}
