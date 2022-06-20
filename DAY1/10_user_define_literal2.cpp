// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 
using namespace std::literals; // C++11 부터 표준이 제공하는
							   // 리터럴 접미사를 사용하기 위해
void foo(const char* s) { std::cout << "char*"; }   // 1
void foo(std::string s) { std::cout << "string"; }  // 2

int main()
{
	foo("hello"); // 1
	foo("hello"s);// 2..  std::string operator""s(const char* )

	std::chrono::seconds s1 = 3s;

	auto m1 = 3min;

	auto h1 = 1h;

	std::chrono::seconds t = 1h + 3min + 2s;

	std::cout << t.count() << std::endl;

//	std::this_thread::sleep_for()
}


