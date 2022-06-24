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

	// ���� �迭, move�迭 ��� ������ �ʾ�����
	// �����Ϸ��� ����
	// main �Լ� �ڵ�� Ȯ��
};

int main()
{
	People p1("kim", 20);
	People p2 = std::move(p1);

	std::cout << p1.name << std::endl; // �ڿ� �̵������Ƿ� ""
}





