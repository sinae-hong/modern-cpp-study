// 4_type_traits3 - 210 page
#include <iostream>

// 표준  traits 를 사용하려면
#include <type_traits>


// C++14 부터 아래 도구가 지원 됩니다.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


template<typename T> void foo(T a)
{
	// traits 의 종류...
	// 1. 조사하려면 : std::is_xxx<T>::value
	bool b1 = std::is_pointer<T>::value;	// C++11
	bool b2 = std::is_pointer_v<T>;			// 위 코드와 동일 - C++17


	// 2. 변형 타입을 얻으려면 : std:xxx_xxx<T>::type
	// 
	typename std::remove_pointer<T>::type n1;
	std::remove_pointer_t<T> n2; // 위와 완전히 동일합니다.(typename 필요 없음)

//	std::remove
}



int main()
{
	int n = 0;
	foo(&n);
}
