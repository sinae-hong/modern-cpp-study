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
	// Cat �� move �����ڰ� ���µ�.. ����ڰ� "std::move" �� ����ߴٸ�
	// => ���� �����ڰ� ���ȴ�.
	// => ������ �ɰ��� ����, ����, ���� ������ ����.
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
			// => �� ĳ������ "lvalue" �� "rvalue"�� �����ϴ� ĳ���� �Դϴ�

	Cat c5 = std::move(c3); // �� �Լ��� ��ó�� ĳ�����ϴ� ���� �ϴ� �Լ� �Դϴ�.
	
	// std::move
	// 1. ����, ���ڸ� rvalue �� ĳ�����ϴ� �ϸ� �մϴ�.
	// 2. ĳ������ ����� �ش� Ÿ���� move �����ڰ� ȣ��ǰ�
	// 3. move �����ڿ��� �ڿ��� move �ϴ� �ڵ尡 �ֽ��ϴ�.

	std::string s1 = "aaa";
	std::string s2 = std::move(s1);
			// �ᱹ string Ŭ���� �ȿ� move �����ڰ� �ֱ� ������ move�� �Ǵ°��Դϴ�
}






