#include <iostream>
#include <type_traits> // �̾ȿ� std::is_pointer �ֽ��ϴ�.

/*
template<typename T> void printv(const T& v)
{
	// if ���� ����ð� ��� �Դϴ�. 
	// => ������ �ð��� if ( false) �� ������ �Ǿ
	// => "template" => "C++ �Լ�����" �Ҷ�, 
	// => "A" �κ��� �ν��Ͻ�ȭ(C++ �ڵ� �����ȴٴ� �ǹ�) �˴ϴ�.
	// => int Ÿ���� *v �Ҽ� �����Ƿ� ������ ����.
	if ( std::is_pointer<T>::value  )

		std::cout << v << " : " << *v << std::endl;  // A

	else

		std::cout << v << std::endl					// B
}
*/
// if constexpr �� �ǹ�
// ������ �����ϴ� �κи� "����"�ϰڴٰ� �ƴ϶�!!
//                      "C++�ڵ�� ����" �ϰڴ�.

template<typename T> void printv(const T& v)
{
	// /std:c++latest �ɼ� �ʿ� 
	if constexpr (std::is_pointer<T>::value)
		std::cout << v << " : " << *v << std::endl;  // A
	else
		std::cout << v << std::endl					// B
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

