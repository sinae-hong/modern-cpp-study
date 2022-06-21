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

	// 깊은복사로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		// 1. 포인터가 아닌 멤버는 그냥 복사
	//	age = c.age; // 여기서 하지말고, 
					// 초기화 리스트에서 하세요

		// 2. 포인터 멤버는 주소가 아니라
		//    메모리 할당후, 메모리 자체를 복사
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
};
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	
					
}






