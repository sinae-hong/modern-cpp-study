#include <iostream>

// fold expression - C++17
// => �Ķ���� ���� ��� ��ҿ� ���� ���׿����� �����ϴ� ��

template<typename ... Types>
auto sum(Types ... args)
{
	// ( pack_name  ���׿��� ... )  <= ���� () �ݵ�� �ʿ�
//	int n = (args + ...); // (1+(2+(3+(4+(5+(6+(7+(8+(9+10))))))))
//	int n = (... + args); // (((((1+2)+3)+4) ....)

	// 0 �� �ʱⰪ(init) �̶�� �մϴ�
//	int n = (args + ... + 0); // (1+(2+(3+(4+(5+(6+(7+(8+(9+(10+ 0))))))))
	
	int n = (0 + ... + args); // (((((0+1)+2)+3)+4) ....)
	return n;
}

int main()
{
//	int n = sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	int n = sum();
	std::cout << n << std::endl;
}