// 145 page
#include <iostream>
int main()
{
	// ����ǥ������ ��Ȯ�� ���
	auto f1 = [](int a, int b) -> int { return a + b; };

	// ���Ϲ��� �Ѱ���� ���� Ÿ�� ��������(�����Ϸ��� auto �� �߷�)
	auto f2 = [](int a, int b)  { return a + b; };

	// ���Ϲ��� ������ ��, ��� ���� Ÿ���̸� ��������
	auto f3 = [](int a, int b) { if (a == 1) return a;  return  b; };


	// ���Ϲ��� ������ �ε�, Ÿ���� �ٸ���, �ݵ�� ����ؾ� �մϴ�.
	auto f4 = [](double a, int b) -> double { if (a == 1) return a;  return  b; };

	
}

