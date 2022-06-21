#include <cstring>
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		std::cout << "copy" << std::endl;
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	/*
	// Cat 에 move 생성자가 없는데.. 사용자가 "std::move" 를 사용했다면
	// => 복사 생성자가 사용된다.
	// => 문제가 될것은 없다, 단지, 빨라 질수는 없다.
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		std::cout << "move" << std::endl;
		c.name = nullptr; 
	}
	*/
};

Cat foo()
{
	Cat c("yaong", 2);
	return c;
}

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// copy

	Cat c3 = foo(); // move

	Cat c4 = static_cast<Cat&&>(c2);
			// => 이 캐스팅은 "lvalue" 를 "rvalue"로 변경하는 캐스팅 입니다

	Cat c5 = std::move(c3); // 이 함수가 위처럼 캐스팅하는 일을 하는 함수 입니다.
	
	// std::move
	// 1. 단지, 인자를 rvalue 로 캐스팅하는 일만 합니다.
	// 2. 캐스팅의 결과로 해당 타입의 move 생성자가 호출되고
	// 3. move 생성자에서 자원을 move 하는 코드가 있습니다.

	std::string s1 = "aaa";
	std::string s2 = std::move(s1);
			// 결국 string 클래스 안에 move 생성자가 있기 때문에 move가 되는것입니다
}






