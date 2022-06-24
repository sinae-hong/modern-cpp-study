#include <iostream>
#include <type_traits> 

// C++20 ������
// "enable_if + SFINAE" �� ������ �������� ���� ���׽��ϴ�.

// C++20 �� "concept" �̶�� �����Դϴ�. �Ʒ� ó�� �ڵ��ϰ� �˴ϴ�.

template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	// ������ �϶�
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	// �����Ͱ� �ƴҶ�
	std::cout << v << std::endl
}





int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

