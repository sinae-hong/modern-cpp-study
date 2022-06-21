#include <iostream>
#include <string>

// rule of 0
// => 내부적으로 "자원을 직접관리하는 코드가 없다면"
// => 5개 special 함수( 소멸자, 복사 생성자, 복사 대입연산자, move 생성자, move 대입)를
//    만들필요 없다.
// => 5개 모두를 만들지 않으면 컴파일러가 모두 기본 구현 제공한다.
//   "가장 좋은 코드"

// 핵심 : 자원관리를 직접 하지 말자.
// char*                ==> std::string
// int* p = new int[10] ==> vector<int> v(10) 또는 스마트 포인터

class People
{
//	char* name;
	std::string name;
	int   age;
	std::string address;
public:
	People(const std::string& s, int a, const std::string& addr = "unknown")
		: name(s), age(a), address(addr)
	{
	}

};

int main()
{
	People p1("kim", 20);
	People p3 = std::move(p1);
}




