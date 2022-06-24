#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types>
void foo(Types ... args)
{
	// args : 1, 2, 3

//	goo(args); // error. pack 은 직접 함수 인자로 사용할수 없다.

	// pack expansion : pack 의 모든 요소를 , 를 사용해서 풀러 달라는 것
	goo(args...); // goo(E1, E2, E3); 

}


int main()
{
	foo(1, 2, 3);
}
