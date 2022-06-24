#include <iostream>
#include <string>

// rule of 0
// => ���������� "�ڿ��� ���������ϴ� �ڵ尡 ���ٸ�"
// => 5�� special �Լ�( �Ҹ���, ���� ������, ���� ���Կ�����, move ������, move ����)��
//    �����ʿ� ����.
// => 5�� ��θ� ������ ������ �����Ϸ��� ��� �⺻ ���� �����Ѵ�.
//   "���� ���� �ڵ�"

// �ٽ� : �ڿ������� ���� ���� ����.
// char*                ==> std::string
// int* p = new int[10] ==> vector<int> v(10) �Ǵ� ����Ʈ ������

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




