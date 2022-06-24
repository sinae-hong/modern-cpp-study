// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// �Ϻ��� ����(perfect forwarding) �̶� ?
// ���޹��� ���ڸ� �ٸ� �Լ����� "��� ��ȭ�� ����" �״�� �����ϴ� ��
// "��, Ÿ��, const ����, value �Ӽ�"�� ��� ���� �״�� ����

// Ư�� �Լ��� ������ �����ϴ� �Լ�
template<typename F>
void chronometry(F f, int arg)
{
	f(arg);

}
int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
