#include <iostream>
// �ٽ� : ���ø� ���� �Ϲ� �Լ��� �켱 ���õȴ�.
//void foo(int a)
//void foo(int& a)
void foo(int&& a)
{
	std::cout << "int" << std::endl;
}
template<typename T>
//void foo(T a)
void foo(T&& a)
{
	std::cout << "T" << std::endl;
}
int main()
{
	int n = 10;
	// ��� Ȯ���� ������
	foo(10);  // �Ϲ��Լ� ��밡�� �ϹǷ� ���
	foo(n);   // �Ϲ��Լ� ���ȵ�(int&& �̹Ƿ�), ���ø� ���
//	foo<int>(n);
	foo<>(n);
	foo<>(10);
}


