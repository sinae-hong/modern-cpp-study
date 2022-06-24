#include <iostream>
// 1. ���� Ÿ���� ǥ��(������ȯ��������) �ϴ� ���
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

// 2. C++14 ���� ���� Ÿ�� ���� �����մϴ�. return ������ Ÿ�� �߷�
// => return ������ ������ �̰�, ���� Ÿ���� �ٸ��� �߷� �ȵ�. 
// => �� ���, ��ó�� ǥ���ؾ� �Ѵ�.
// => return ǥ������ ����� ����(int&)��� ������ �����ϰ� Ÿ�� ����(int��ȯ)
template<typename T1, typename T2>
auto Mul2(T1 a, T2 b)
{
	return a * b;
}
// C++14 ����, �Ʒ�ó���� ����
// => return ���� ����� ���� ��� ���� Ÿ�Ե� ������ �ش޶�� ��
// => �� ǥ����� �� �θ� ����.
template<typename T1, typename T2>
decltype(auto) Mul2(T1 a, T2 b)
{
	return a * b;
}


int main()
{
	std::cout << Mul(1, 2.2) << std::endl;
}


