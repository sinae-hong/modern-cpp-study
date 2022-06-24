// 4_type_traits3 - 210 page
#include <iostream>

// ǥ��  traits �� ����Ϸ���
#include <type_traits>


// C++14 ���� �Ʒ� ������ ���� �˴ϴ�.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


template<typename T> void foo(T a)
{
	// traits �� ����...
	// 1. �����Ϸ��� : std::is_xxx<T>::value
	bool b1 = std::is_pointer<T>::value;	// C++11
	bool b2 = std::is_pointer_v<T>;			// �� �ڵ�� ���� - C++17


	// 2. ���� Ÿ���� �������� : std:xxx_xxx<T>::type
	// 
	typename std::remove_pointer<T>::type n1;
	std::remove_pointer_t<T> n2; // ���� ������ �����մϴ�.(typename �ʿ� ����)

//	std::remove
}



int main()
{
	int n = 0;
	foo(&n);
}
