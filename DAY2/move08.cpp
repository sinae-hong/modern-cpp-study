#include <iostream>
#include <string>

// "���� �迭������ ��� ����� �����"
// "move �迭������ ��� ����� move��"

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
	//	: name(p.name), age(p.age), address(p.address) // �߸��� ����
														// string(address)�� ���������ȣ��
		: name(p.name), age(p.age), address(std::move(p.address))
													// => string �� move �����ڰ� ȣ��ǵ���
													//    �̷��� �����ؾ� �մϴ�.
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

		address = std::move(p.address); // People �� move ���Կ����ڿ�����
										// ��� ��ü�� ����� "move ����"���� �Űܶ�!

		return *this;

	}


};

int main()
{
	People p1("kim", 20);
	People p3 = std::move(p1);
}




