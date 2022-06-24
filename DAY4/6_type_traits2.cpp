#include <iostream>
#include <type_traits>

// type traits - C++11 ���� ���Ե� ���̺귯��
// => Ÿ�Կ� ���� �پ��� Ư¡(Ư��)�� �����ϴ� ����
// => <type_traits> ����� ���ʰ��� traits ����
// => �����Ϸ��� ������ �ð��� ����Ҽ� �ִ� (��Ÿ)�Լ���

// => static_assert, if constexpr( ) �� "������ �ð��� ������ �ʿ��� �ڸ�"�� ��밡��


// T�� ������ ���� �����ϴ� �ڵ�
template<typename T> struct is_pointer
{
	enum { value = false };
};

template<typename T> struct is_pointer<T*>
{
	enum { value = true };
};


template<typename T> void foo(const T& a)
{
	// T : int, int*  �Դϴ�.(main ����)
	if ( is_pointer<T>::value )
		std::cout << "������" << std::endl;
	else
		std::cout << "������ �ƴ�" << std::endl;
}






int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}