#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
//	printv(args...);  // error.  printv( 1, 2, 3) 으로 코드가 생성되므로
	
//	printv(args)...;	// printv(1), printv(2), printv(3) 을 기대하지만...
						// error

	// pack expansion 이 가능한 위치
	// 1. 함수 호출의 () 안..
	// 2. 초기화에 사용되는 {} 안...

	int dummy[] = {  0, (printv(args), 0)... }; 
				// { (printv(1), 0)   , (printv(2), 0) , (printv(3), 0) }
				// {}
}


int main()
{
	foo();
//	foo(1, 2, 3);
}

