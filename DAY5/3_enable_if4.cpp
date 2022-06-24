#include <iostream>
#include <type_traits>

// ���� C++�� "Ư�� Ÿ��" �� ���� �Լ� �����ε���
// ���� �մϴ�.
void foo(int)    {}
void foo(double) {}

// "Ÿ��"�� �ƴ� "Ư�� ������ �����ϴ� Ÿ�Ե�"�� ���� �����ε��� ������
// ���� ������� ?
//void goo(�����Լ����ִ�Ŭ������) {}
//void goo(�����Լ�������Ŭ������) {}

// ��ȯ Ÿ�� �ڸ��� : enable_if_t<����, ��ȯŸ��> �ε�..
//					��ȯ Ÿ�� ������ void �� ����ȴ�.

template<typename T>
//std::enable_if_t< �����Լ����ִ�Ÿ��, void>
//std::enable_if_t< std::is_polymorphic_v<T>,  void>
std::enable_if_t< std::is_polymorphic_v<T> >
goo(T a)
{
	std::cout << "�����Լ��� �ִ� Ÿ�Կ� ���� �˰���" << std::endl;
}

template<typename T>
std::enable_if_t< !std::is_polymorphic_v<T> >
goo(T a)
{
	std::cout << "�����Լ��� ���� Ÿ�Կ� ���� �˰���" << std::endl;
}

class A
{
public:
	virtual void f() {}
};

int main()
{
	A a;
	goo(a);
}




