#include<iostream>
#include<algorithm>
#include<random>
#include<iomanip>
#include"save.h"
using namespace std;


//전역 데이터는 실행 파일의(어디에)(어떻게) 기록되는가?
//int a[100];
//int a[100]{1};
//위 두방식의 차이점을 설명해 보자.


//사용자가 원하는 만큼 정수를 입력받는다
//임의의 값으로 채운다, uid(dre)이용
//오름차순 정렬 후 100개를 출력해보자.

int main()
{
	while(true){
		cout << "원하는 정수 갯수를 입력하세요: ";
		int num;
		cin >> num;

		int* a = new int[num];

		default_random_engine dre;
		uniform_int_distribution<> uid;
		for (int i = 0; i < num; ++i)
			a[i] = uid(dre);

		cout << "정렬 전 100개" << endl;
		for (int i = 0; i < 100; ++i) {
			cout << setw(12) << a[i] << ' ';
			if (i % 6 == 0)
				cout << endl;
		}
		cout << endl;
		cout << endl;

		sort(&a[0], a + num);

		cout << "정렬 후 100개" << endl;
		for (int i = 0; i < 100; ++i) {
			cout << setw(12) << a[i] << ' ';
			if (i % 6 == 0)
				cout << endl;
		}
		cout << endl;
		delete[] a;
	}
	
	save("소스.cpp");
	

}
