#include <iostream>

#include <vector>

// �Լ� ��ü�� ���ۻ� �ƴ϶� "����"�� ������ �ֽ��ϴ�(��� ����Ÿ�� �ִٴ� �ǹ�)
// ����, ������/�Ҹ���/���� ������ � Ȱ�밡���մϴ�. 
// �Լ� ó�� ���������, �Լ� ���� ����� �����ϴ�

class URandom
{
	std::vector<int> history;
public:
	int operator()()
	{
		return rand() % 10;
	}
};
URandom urand; // ��ü���� "operator()" �����ڰ� ������ �Ǿ �Լ�ó�� ��밡��


int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << urand() << std::endl;
	}
}