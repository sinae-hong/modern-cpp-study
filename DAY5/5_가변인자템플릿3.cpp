#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types>
void foo(Types ... args)
{
	// args : 1, 2, 3
//	goo(args); // error. pack �� ���� �Լ� ���ڷ� ����Ҽ� ����.

	// pack expansion : pack �� ��� ��Ҹ� , �� ����ؼ� Ǯ�� �޶�� ��
	goo(args...);	// goo(E1, E2, E3); 
					// goo(1,2,3)

	// pack expansioin : "pack������ϴ� ����..." => E1����, E2����, E3����
	goo(++args...); // goo(++E1, ++E2, ++E3)
					// goo(2,3,4)

//	goo( hoo(args...) );	// goo( hoo( 2,3,4) ) �� ����� �Ǵµ�, hoo �� ���ڰ� �Ѱ�
							// error

	goo( hoo(args)... );	// goo( hoo(2), hoo(3), hoo(4))


}



int main()
{
	foo(1, 2, 3);
}
