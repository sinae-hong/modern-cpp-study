// ����ǥ����4-1
// 142 page
#include <iostream>

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
			// class xxx { public: int operator()(int a, int b) { return a + b;} };
			// auto f1 = xxx(); �� ����ε�, �ᱹ
			// xxx  f1;         �� �����մϴ�

	auto f2 = [](int a, int b) { return a + b; };
			// class yyy{}; yyy();  

	// ����ǥ������ ���� �����Ϸ��� ���� Ŭ���� �̸� Ȯ�� �ϴ� ���
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;

	// �ٽ� 1. ��� ����ǥ������ "�ٸ� Ÿ��" �Դϴ�
	//      2. ����ǥ�������� �ʱ�ȭ�� auto ������ �ٸ� ����ǥ���� ������ �����ϴ�

	auto f3 = [](int a, int b) { return a + b; };

	f3 = [](int a, int b) { return a + b; }; // error. 
											// f3�� Ÿ�԰� �캯�� Ÿ���� ������ �ٸ��ϴ�.


}




