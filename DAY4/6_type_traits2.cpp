#include <iostream>
#include <type_traits>

// type traits - C++11 부터 도입된 라이브러리
// => 타입에 대한 다양한 특징(특질)을 조사하는 도구
// => <type_traits> 헤더에 수십개의 traits 제공
// => 컴파일러가 컴파일 시간에 사용할수 있는 (메타)함수들

// => static_assert, if constexpr( ) 등 "컴파일 시간에 결정이 필요한 자리"에 사용가능


// T가 포인터 인지 조사하는 코드
template<typename T> struct is_pointer
{
	enum { value = false };
};

template<typename T> struct is_pointer<T*>
{
	enum { value = true };
};


template<typename T> void foo(const T& a)
{
	// T : int, int*  입니다.(main 참고)
	if ( is_pointer<T>::value )
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}






int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}