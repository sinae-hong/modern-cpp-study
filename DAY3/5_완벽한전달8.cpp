#include <iostream>

void f0() {}
void f1(int a) {}

int& f3(int a, int& r, double d) { r = 200; return r; }

// �Ϻ��� ������ ����Ϸ���
// 1. ���ڸ� �������� "T&& - forwarding reference" ���
// 2. ���ڸ� �ٸ����� �������� "std::forward<T>(arg)" �� ��� ����
// 3. ���� ������ ������ ���� �Ϸ��� "�������� ���ø� ���"

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f(std::forward<T>(arg)...);
}
int main()
{
	int n = 10;
	chronometry(f0);
	chronometry(f1, 10);

	int& r = chronometry(f3, 10, n, 3.4);
	
	// �ᱹ r�� n�� �����Դϴ�.
	std::cout << &r << std::endl;
	std::cout << &n << std::endl;

	std::cout << n << std::endl; // 200
}
