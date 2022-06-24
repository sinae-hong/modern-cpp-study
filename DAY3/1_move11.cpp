#include <iostream>
#include <string>

class People
{
public:
	std::string name;
	int   age;
	std::string address;
public:
	People(const std::string& s, int a, const std::string& addr = "unknown")
		: name(s), age(a), address(addr)
	{
	}

	// 복사 계열, move계열 모두 만들지 않았지만
	// 컴파일러가 제공
	// main 함수 코드로 확인
};

int main()
{
	People p1("kim", 20);
	People p2 = std::move(p1);

	std::cout << p1.name << std::endl; // 자원 이동했으므로 ""
}





