#include <iostream>
#include <string>

// "복사 계열에서는 모든 멤버를 복사로"
// "move 계열에서는 모든 멤버를 move로"

class People
{
	char* name;
	int   age;
	std::string address;
public:
	People(const char* s, int a, const std::string& addr = "unknown")
				: age(a), address(addr)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}

	~People() { delete[] name; }

	People(const People& p) : age(p.age), address(p.address)
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}

	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		delete[] name;

		address = p.address;
		age = p.age;
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);

		return *this;

	}

	People(People&& p) 
	//	: name(p.name), age(p.age), address(p.address) // 잘못된 구현
														// string(address)의 복사생성자호출
		: name(p.name), age(p.age), address(std::move(p.address))
													// => string 의 move 생성자가 호출되도록
													//    이렇게 구현해야 합니다.
	{
		p.name = nullptr;
	}

	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		delete[] name;

		age = p.age;
		name = p.name;
		p.name = nullptr;

		address = std::move(p.address); // People 의 move 대입연산자에서는
										// 모든 객체형 멤버를 "move 대입"으로 옮겨라!

		return *this;

	}


};

int main()
{
	People p1("kim", 20);
	People p3 = std::move(p1);
}




