// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}
// �Ϻ��� ������ �Ϸ��� 
// 1. int& �� int&& ������ ���� �����ؾ� �Ѵ�.
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}
int main()
{
	int n = 10;
	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);
	std::cout << n << std::endl;

	hoo(10); // ok
	chronometry(hoo, 10);// error.. 
}
