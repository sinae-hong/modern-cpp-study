#include <iostream>
#include <type_traits> // 이안에 std::is_pointer 있습니다.

/*
template<typename T> void printv(const T& v)
{
	// if 문은 실행시간 제어문 입니다. 
	// => 컴파일 시간에 if ( false) 로 결정이 되어도
	// => "template" => "C++ 함수생성" 할때, 
	// => "A" 부분이 인스턴스화(C++ 코드 생성된다는 의미) 됩니다.
	// => int 타입을 *v 할수 없으므로 컴파일 에러.
	if ( std::is_pointer<T>::value  )

		std::cout << v << " : " << *v << std::endl;  // A

	else

		std::cout << v << std::endl					// B
}
*/
// if constexpr 의 의미
// 조건을 만족하는 부분만 "실행"하겠다가 아니라!!
//                      "C++코드로 생성" 하겠다.

template<typename T> void printv(const T& v)
{
	// /std:c++latest 옵션 필요 
	if constexpr (std::is_pointer<T>::value)
		std::cout << v << " : " << *v << std::endl;  // A
	else
		std::cout << v << std::endl					// B
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

