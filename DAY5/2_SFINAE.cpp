// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }
//void foo(int a) { std::cout << "int" << std::endl; }
void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3);		// 1. int ���� ȣ�� - exactly matching
				// 2. T �� ����ؼ� foo(int) ���� ����
				//    => ��Ȯ�� Ÿ���� �Լ��� ����� �����Ƿ�...
				// 3. ... ���� ȣ��

				// ...�� ���ٸ� "�Լ��� ã���� ����"�� ����
	// �ٽ� : �Լ� ã�� ���� �˾� �μ���( "C++ overloading resolutioin" �˻�)
}

