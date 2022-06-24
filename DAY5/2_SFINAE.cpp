// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }
//void foo(int a) { std::cout << "int" << std::endl; }
void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3);		// 1. int 버전 호출 - exactly matching
				// 2. T 를 사용해서 foo(int) 버전 생성
				//    => 정확한 타입의 함수를 만들수 있으므로...
				// 3. ... 버전 호출

				// ...도 없다면 "함수를 찾을수 없다"는 에러
	// 핵심 : 함수 찾는 순서 알아 두세요( "C++ overloading resolutioin" 검색)
}

