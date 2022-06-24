#include <iostream>

// 90 page
void foo(int& a)       { std::cout << "int&" << std::endl; }		// 1. lvalue �޴��Լ�
void foo(const int& a) { std::cout << "const int&" << std::endl; }	// 2. lvalue/rvalue 
void foo(int&& a)      { std::cout << "int&&" << std::endl; }		// 3. rvalue �޴��Լ�

int main()
{
	int n = 10;
	foo(n);		// 1�� ȣ��, ������ 2�� ȣ��
	foo(10);	// 3�� ȣ��, ������ 2�� ȣ��

	int& r1 = n;
	foo(r1);	// 1�� ȣ��, ������ 2�� ȣ��


	int&& r2 = 10; 
	foo(r2);	// �ٽ� !! ��� ȣ���ұ�� ?  1��.
		
	// int&& r2 = 10 ����
	// int n = 10
	//			����Ÿ Ÿ��		value �Ӽ�
	// 10		int				rvalue
	// n		int				lvalue
	// r2		int&&			lvalue

	foo(r2); // r2�� int&& Ÿ��������, �̸��� �����Ƿ� lvalue
			// 1�� ȣ��

	foo(static_cast<int&&>(r2)); // 3�� ȣ��Ƿ���, lvalue �� r2�� "rvalue"�� ����(ĳ����)�ؾ� �Ѵ�.
						// �� �ڵ�� Ÿ�� ĳ������ �ƴմϴ�.
						// value �Ӽ��� �����ϴ� casting �Դϴ�.
						// cppreference.com ���� "static_cast �˻�"
						
}
void f1(int&)  {} // int& �� �ްڴٴ� ���� �ƴ϶� int Ÿ���� "lvalue" �� �ްڴٴ°�
void f1(int&&) {} // int&& �� �ްڴٴ� ���� �ƴ϶� int Ÿ���� "rvalue" �� �ްڴٴ°�









