#include <iostream>

// ��Ģ 1. ��Ÿ������ ������
//  �Լ������� "const, volatile, reference"������ T����
//  T�� Ÿ���� �ᱹ a�� Ÿ��
template<typename T> void foo(T a)
{
	
}
// ��Ģ 2. ������ ������
// �Լ������� "reference" ������ T�� Ÿ�� ����
// const, volatile�� ����
// T�� �����Ǹ� & �� �ٿ��� a�� Ÿ�԰���
// T�� int ��� a�� int&

template<typename T> void goo(T& a)
{
	// T �� Ÿ���� �����ϴ� ���
	// 1. C++ RTTI ��� ���
	// => const, volatile,reference �� ��µ��� �ʽ��ϴ�. �̷��� �������� ������
//	std::cout << typeid(T).name() << std::endl;

	// 2. �Լ� �̸��� ����ؼ� ����
	// __FUNCTION__ : �Լ� �̸��� ���� ��ũ��. C++ ǥ��
	// __FUNCSIG__  : �Լ� �̸� + �Լ� ���� .  C++ ǥ�ؾƴ�, MS ����
	// __PRETTY_FUNCTION__ : ���� ���� ���, g++ ����

	//std::cout << __FUNCTION__ << std::endl;
	//std::cout << __FUNCSIG__ << std::endl;

	// 3. godbolt.org ���� Ȯ���ϼ���..

}


int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T : int
	foo(c);  // T : int
	foo(r);  // T : int 
	foo(cr); // T : int

	goo(n);  // T : int          a : int&
	goo(c);  // T : const int    a : const int&
	goo(r);  // T : int          a : int&
	goo(cr); // T : const int    a : const int&
}