#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
//	printv(args...);  // error.  printv( 1, 2, 3) ���� �ڵ尡 �����ǹǷ�
	
//	printv(args)...;	// printv(1), printv(2), printv(3) �� ���������...
						// error

	// pack expansion �� ������ ��ġ
	// 1. �Լ� ȣ���� () ��..
	// 2. �ʱ�ȭ�� ���Ǵ� {} ��...

	int dummy[] = {  0, (printv(args), 0)... }; 
				// { (printv(1), 0)   , (printv(2), 0) , (printv(3), 0) }
				// {}
}


int main()
{
	foo();
//	foo(1, 2, 3);
}

