// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
// main					chronometry						hoo(int&&)
// hoo(10) =============================================> ok
// chronometry(10)===> "int&& arg = 10"
//							hoo(arg) ===================> error. arg�� lvalue
//							hoo(static_cast<int&&>(arg)) ===> ok
template<typename F> void chronometry(F f, int&& arg)
{
	// ���� ���Լ��� ȣ���Ҷ� 2��° ���ڴ� rvalue ���´µ�..
	// ���ڸ� �����鼭 lvalue �� �Ǿ���.
	// "chronometry(hoo, 10)" => "int&& arg = 10"
	// ��, 10 �� arg�� ����
//	f(arg); // error. hoo(int&) �� ã�� �ȴ�.
	f(static_cast<int&&>(arg));
}
int main()
{
	hoo(10); 

	chronometry(hoo, 10);
}
