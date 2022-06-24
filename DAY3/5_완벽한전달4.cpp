// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// 1. int& �� int&& ������ ���� ������
// 2. int&& ���������� ���ڸ� forwarding �Ҷ� "rvalue �� ĳ����" �ؼ� ������
/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg)); // �ʿ���� ĳ���������� �־ �˴ϴ�.(�����Ͻ����ŵ�)
							   // �̷��� �ϸ� �Ʒ��� ������ ������ ���ϴ�.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/

template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 10;
	chronometry(goo, n);	// T=int&		T&&=int&    �������Լ�:chronometry(int&)
							// => static_cast<int& >(arg)

	chronometry(hoo, 10);	// T=int		T&&=int&&   �������Լ�:chronometry(int&&)
							// => static_cast<int&&>(arg)
}
