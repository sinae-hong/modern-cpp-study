#include <iostream>

// Rule Of 3
// => 클래스가 포인터 멤버가 있고, 자원할당을 하고 있다면
//    3개의 멤버 함수를 반드시 만들어야 한다는 것
//    "소멸자", "복사생성자", "대입연산자"

// Rule Of 5
// => C++11 부터는 2개의 멤버 함수를 더 만드는 것이 좋다.
//    "move생성자", "move 대입연산자"

class People
{
	char* name;
	int   age;
public:
	People(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s)+1, s);
	}

	~People() { delete[] name; }

	People(const People& p) : age(p.age)
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}

	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		delete[] name;

		age = p.age;
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);

		return *this;
		
	}

	People(People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr;
	}

	// 아래 함수가 "move 대입연산자" 입니다.
	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		delete[] name;

		age = p.age;
		name = p.name;
		p.name = nullptr;

		return *this;

	}


};

int main()
{
	People p1("kim", 20);
	
	People p2 = p1;  // 만들면서 넣는것, 복사 생성자

	p2 = p1;		// 만들어진 객체에 넣는것, 대입연산자
					// p2.operator=(p1);



	People p3 = std::move(p1);
	p3 = std::move(p2);		  
}




