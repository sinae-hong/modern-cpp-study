#include <iostream>

// 2���� ���ڰ� ���� �ٸ� Ÿ���� �ɼ� �ֵ���
template<typename T1, typename T2>
//?? Mul(T1 a, T2 b)  // ? �� ä��� ��������ϴ�.

//decltype(a * b) Mul(T1 a, T2 b) // �׷���, decltype()�� ��������ϴ�.
								// => �׷���, �� �����ϱ�� ?
								// => a, b �� �������� ���˴ϴ�.
auto Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(1, 2.2) << std::endl;			

//	a = 20;// error. ������ �������� ���
//	int a;
//	a = 10; // ok.. ������ ������ ���
}


