#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<iterator>
#include<chrono>

//파일 save하기
//큰데이터 다루기
//파일을 읽고 쓰기

void save(std::string fname)
{
	//fname을 읽기 모드로 읽기
	std::ifstream in(fname);
	if (!in)
		std::cout << "Failed" << std::endl;
	//기록할 파일을 덧붙여 쓰기 모드로 연다
	std::ofstream out("2019 STL.txt");
	//실행된 시간을 기록한다.
	//시간기원에서 몇 tic이 흘렀나 값을 가져와서 time_t로 변환
	//변환값을 글자로 변환
	auto tic = std::chrono::system_clock::now();
	auto timer = std::chrono::system_clock::to_time_t(tic);
	std::string date = ctime(&timer);

	out << std::endl << std::endl << "==============================" << std::endl;
	out << date;
	out << "==============================" << std::endl;
	out << std::endl;

	//fname의 모든내용을 입력한다.
	std::copy(std::istreambuf_iterator<char>(in),
		std::istreambuf_iterator<char>(),
		std::ostreambuf_iterator<char>(out)
	);
}