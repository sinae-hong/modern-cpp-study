// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits �� ����
// 1. Ÿ������ : is_xxx<T>::value
// 2. ����Ÿ�Ծ�� : xxx<T>::type

// 1. ����ü ���ø��� ����� "using type = T" �� �ִ´�. 
template<typename T> struct remove_pointer
{
	using type = T;	// �Ǵ� typedef T type;
};

// 2. ������ �����ϵ��� �κ� Ư��ȭ ������ ����
//    T* => T �� * �� �и��Ѵ�.
template<typename T> struct remove_pointer<T*>
{
	using type = T;	
};

int main()
{
	remove_pointer<int*>::type n2;	// int* ���� �����͸� ������ Ÿ�� �̹Ƿ�
									// int n2
}

template<typename T> void foo(T a)
{
	// ���� !! 
	remove_pointer<int*>::type n1; // T �� �������� �ʽ��ϴ�. typename �ʿ� �����ϴ�
	remove_pointer<T>::type n2;    // T �� �����մϴ�.   error  typename �ʿ� �մϴ�

	typename remove_pointer<T>::type n3;  //  ok..
}