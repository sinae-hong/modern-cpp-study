// 143 
#include <functional>

int main()
{
	// ����ǥ������ ��� ���
	// �ٽ� : ����ǥ������ ��������� "�ӽð�ü(rvalue)" �Դϴ�.
	auto  f1       = [](int a, int b) { return a + b; }; // ok
	auto& f2       = [](int a, int b) { return a + b; }; // error
	const auto& f3 = [](int a, int b) { return a + b; }; // ok
	auto&& f4      = [](int a, int b) { return a + b; }; // ok

	// ��, �� ǥ����߿����� "f1"�� ���� �����ϴ�. f1 ó�� ����ϼ���

	// ����ǥ������ �Լ� �����Ϳ� ������ �ֽ��ϴ�. - ������ �ڿ��� ����
	int(*f5)(int, int) = [](int a, int b) { return a + b; }; 
						// class xxx{}; xxx();

	// ����ǥ������ "STL" �� function �� ������ �ֽ��ϴ�.
	std::function<int(int,int)> f6 = [](int a, int b) { return a + b; };

	// �ٽ� 1. ����ǥ������ "auto ����, �Լ�������, std::function �� ������ �ֽ��ϴ�."
	// 2. �Լ������ͳ�, function �� ���� ���, �ٸ� ���ٷ� �ٲܼ� �ֽ��ϴ�
	f5 = [](int a, int b) { return a - b; }; // ok.. f5 �Լ� ������
	f1 = [](int a, int b) { return a - b; }; // error

}


void foo(int(*)(int, int))
{
}
foo( [](int a, int b) { return a + b; } );





