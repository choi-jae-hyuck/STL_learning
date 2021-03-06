#include<iostream>
#include<algorithm>
#include<random>
#include"save.h"
using namespace std;
int a[10000];

int main()
{
	//정수 10개를 정렬화 하기

	//int a[](1,3,5,7,9,10); uniform initialization, {1,2,3,4,5}-initialize list
	default_random_engine dre;
	uniform_int_distribution<int> uid(0, 1000);
	for (int& d : a)
		d = uid(dre);

	bool how(int, int);
	sort(begin(a), end(a), [](int a, int b) {return a > b; });//오름차순 ascending 내림차순 descending
	for (int d : a)
		cout << d << ' ';
	cout << endl;

	save("소스.cpp");
	

}
