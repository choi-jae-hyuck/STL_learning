#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<iterator>
#include<chrono>

//���� save�ϱ�
//ū������ �ٷ��
//������ �а� ����

void save(std::string fname)
{
	//fname�� �б� ���� �б�
	std::ifstream in(fname);
	if (!in)
		std::cout << "Failed" << std::endl;
	//����� ������ ���ٿ� ���� ���� ����
	std::ofstream out("2019 STL.txt");
	//����� �ð��� ����Ѵ�.
	//�ð�������� �� tic�� �귶�� ���� �����ͼ� time_t�� ��ȯ
	//��ȯ���� ���ڷ� ��ȯ
	auto tic = std::chrono::system_clock::now();
	auto timer = std::chrono::system_clock::to_time_t(tic);
	std::string date = ctime(&timer);

	out << std::endl << std::endl << "==============================" << std::endl;
	out << date;
	out << "==============================" << std::endl;
	out << std::endl;

	//fname�� ��系���� �Է��Ѵ�.
	std::copy(std::istreambuf_iterator<char>(in),
		std::istreambuf_iterator<char>(),
		std::ostreambuf_iterator<char>(out)
	);
}