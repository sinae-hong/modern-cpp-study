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

	// 임시객체일 경우를 고려해서
	// 복사 생성자를 한개 더 만들자
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		std::cout << "move" << std::endl;
		// 임시객체의 자원 포인터는 reset
		c.name = nullptr; // 이 코드가 되려면
							// 임시객체라도 쓰기가 가능해야 한다.
							// 그래서, "상수성 없이 임시객체를 가리킬 필요"
							// 가 있다.

	}
};

Cat foo()
{
	Cat c("yaong", 2);
	return c;
}

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;

	Cat c3 = foo(); // 핵심.. 잘 생각해 보세요.
}






