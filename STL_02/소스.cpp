#include<iostream>
#include<algorithm>
#include<random>
#include<iomanip>
#include"save.h"
using namespace std;


//���� �����ʹ� ���� ������(���)(���) ��ϵǴ°�?
//int a[100];
//int a[100]{1};
//�� �ι���� �������� ������ ����.


//����ڰ� ���ϴ� ��ŭ ������ �Է¹޴´�
//������ ������ ä���, uid(dre)�̿�
//�������� ���� �� 100���� ����غ���.

int main()
{
	while(true){
		cout << "���ϴ� ���� ������ �Է��ϼ���: ";
		int num;
		cin >> num;

		int* a = new int[num];

		default_random_engine dre;
		uniform_int_distribution<> uid;
		for (int i = 0; i < num; ++i)
			a[i] = uid(dre);

		cout << "���� �� 100��" << endl;
		for (int i = 0; i < 100; ++i) {
			cout << setw(12) << a[i] << ' ';
			if (i % 6 == 0)
				cout << endl;
		}
		cout << endl;
		cout << endl;

		sort(&a[0], a + num);

		cout << "���� �� 100��" << endl;
		for (int i = 0; i < 100; ++i) {
			cout << setw(12) << a[i] << ' ';
			if (i % 6 == 0)
				cout << endl;
		}
		cout << endl;
		delete[] a;
	}
	
	save("�ҽ�.cpp");
	

}
