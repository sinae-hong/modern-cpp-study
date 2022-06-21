#include <iostream>

// Rule Of 3
// => Ŭ������ ������ ����� �ְ�, �ڿ��Ҵ��� �ϰ� �ִٸ�
//    3���� ��� �Լ��� �ݵ�� ������ �Ѵٴ� ��
//    "�Ҹ���", "���������", "���Կ�����"

// Rule Of 5
// => C++11 ���ʹ� 2���� ��� �Լ��� �� ����� ���� ����.
//    "move������", "move ���Կ�����"

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

	// �Ʒ� �Լ��� "move ���Կ�����" �Դϴ�.
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
	
	People p2 = p1;  // ����鼭 �ִ°�, ���� ������

	p2 = p1;		// ������� ��ü�� �ִ°�, ���Կ�����
					// p2.operator=(p1);



	People p3 = std::move(p1);
	p3 = std::move(p2);		  
}




