#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
	std::string addr;
public:
	// 생성자를 생각해 봅시다.
	// 인자가 한개인 생성자를 move 지원하기 - 2개의 생성자
	People(const std::string& s) : name(s) {}
	People(std::string&& s) : name(std::move(s)) {}

	// 인자가 2개인 생성자를 move 지원하려면 "4개"의 함수
	// 인자가 N개인 생성자를 move 지원하려면 "2^N"의 함수 => 다른 방법이 없을까 ?? 오늘 오후!!
	People(const std::string& s1, const std::string& s2) : name(s1), addr(s2) {}
	People(const std::string& s1, std::string&& s2)      : name(s1), addr(std::move(s2)) {}
	People(std::string&& s1,      const std::string& s2) : name(std::move(s1)), addr(s2) {}
	People(std::string&& s1,	  std::string&& s2)		 : name(std::move(s1)), addr(std::move(s2)) {}
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "seoul";
//	People p1(s1);
//	People p2(std::move(s1));

	People p3(s1, s2);
	People p4(s1, std::move(s2));

}
















