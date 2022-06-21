#include <iostream>

// ��Ģ 1. �� Ÿ������ ������(T arg)
// => �Լ� ���ڰ� ������ "const, volatile, reference" �� �����ϰ� 
//    Ÿ�� ����
template<typename T> void foo(T a)
{
	a = 100;
}
int main()
{
	foo<int>(3.4); // Ÿ���� ���� ����
				   // ������ "T=int"

	// T�� Ÿ���� ������ ������
	foo(10); // T = int
	foo(3.4);// T = double

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
//	volatile int k = 0;
	foo(n); // T = int
	foo(c); // T = int
	foo(r); // T = int
	foo(cr);// T = int

	// ���� ! ���ڰ� ������ const �� �����ϰ� �ؾ� �մϴ�
	const char* const s = "abcd";
	foo(s);  // T = const char*     => ������ const�� ����
			//						=> ����Ű�� ���� const ��� ���� ����
}

