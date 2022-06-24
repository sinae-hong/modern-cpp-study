#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}


// 1. T&& �� ������ ���� Ÿ���� lvalue, rvalue �� ���纻 ����, ������߰�����
//    ������ �ִ�.

// 2. ��, rvalue(10) �� ������ �����鼭 �̸��� ������ �ǰ� lvalue �� �ȴ�.

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// �Ʒ� 2���� �ڵ�� �׻� "rvalue" �� ĳ����
	static_cast<int&&>(arg); // �׻�, int Ÿ���� rvalue �� ĳ����
	std::move(arg); // �׻�, T Ÿ���� rvalue �� ĳ����

	// �Ʒ� ĳ������ ��Ȳ�� ���� �޶����� ĳ����
	// chronometry() �� 2��° ���ڷ�
	// lvalue(n)  �� ������ T=int& �̹Ƿ� lvalue �� ĳ����
	// rvalue(10) �� ������ T=int  �̹Ƿ� rvalue �� ĳ����
	// => rvalue(10) �� ������ �����鼭 lvalue �� ���ߴµ�, �װ��� �ٽ� rvalue �� ĳ����
	// => ����, "lvalue �� lvalue �� rvalue �� rvalue �� ĳ���� �Ѵ�" ��� ǥ���մϴ�
//	f(static_cast<T&&>(arg));

	f( std::forward<T>(arg) ); //�� �ڵ尡 ���� �����մϴ�.(��ó�� ĳ����)
								// T&& �� �ƴ϶� T�� �����ϸ� �˴ϴ�.

	// �� ����Ұ�
	// std::move    : �׻� rvalue �� ĳ����
	// std::forward : ��Ȳ�� ���� �ٸ� ĳ����
	//				 lvalue �� lvalue �� rvalue �� rvalue ��!
}
int main()
{
	int n = 10;
	chronometry(goo, n);	
	chronometry(hoo, 10);	
}
