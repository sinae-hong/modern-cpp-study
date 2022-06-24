#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types>
void foo(Types ... args)
{
	// args : 1, 2, 3
//	goo(args); // error. pack 은 직접 함수 인자로 사용할수 없다.

	// pack expansion : pack 의 모든 요소를 , 를 사용해서 풀러 달라는 것
	goo(args...);	// goo(E1, E2, E3); 
					// goo(1,2,3)

	// pack expansioin : "pack을사용하는 패턴..." => E1패턴, E2패턴, E3패턴
	goo(++args...); // goo(++E1, ++E2, ++E3)
					// goo(2,3,4)

//	goo( hoo(args...) );	// goo( hoo( 2,3,4) ) 의 모양인 되는데, hoo 는 인자가 한개
							// error

	goo( hoo(args)... );	// goo( hoo(2), hoo(3), hoo(4))


}



int main()
{
	foo(1, 2, 3);
}
