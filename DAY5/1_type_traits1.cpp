#include <iostream>
#include <type_traits>

template<typename T> struct is_pointer
{

	// �� enum ����� ����մϱ� ?
	// bool value = false; // 1. C++11 �������� �̷��� �ʱ�ȭ �ȵǰ�..
						   // 2. �̰�� ���� �̹Ƿ� ������ �ð��� ����� ����Ҽ� ����
	
	// �׷���, C++11 �������� �Ʒ� ��� �ۿ� �������ϴ�.
//	enum { value = false };

	// �׷���, ������ enum ��� �Ʒ� ������� �մϴ�.
	static constexpr bool value = false;
};

template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};


template<typename T> void foo(const T& a)
{

	if (is_pointer<T>::value)
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