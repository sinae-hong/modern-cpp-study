#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args �ȿ��� "2��° ���" ������ �ͽ��ϴ�.
	// => ���� ������ ����� �����ϴ�.

	// args �� �ִ� ��� ��Ҹ� ������ �ʹٸ�
	// 1. pack expansion - C++11
	// 2. fold expression - C++17 
	
	// ��� 1. ��� ����� Ÿ���� �����ϸ� - �迭�� ��Ƽ� ����ص� �˴ϴ�.
	int x[] = { args... };

	// ��� 2. ����� Ÿ���� �ٸ���.. std::tuple �� ��Ƽ� ����ص� �˴ϴ�.
	std::tuple<Types...> t(args...);

	std::cout << std::get<0>(t) << std::endl; // Ʃ�ÿ��� 0��° ������.
}


int main()
{
	foo(1, 2, 3);
}

