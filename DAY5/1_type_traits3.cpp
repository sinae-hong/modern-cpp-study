// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// 1. 구조체 템플릿을 만들고 "using type = T" 를 넣는다. 
template<typename T> struct remove_pointer
{
	using type = T;	// 또는 typedef T type;
};

// 2. 조건을 만족하도록 부분 특수화 버전을 만들어서
//    T* => T 와 * 로 분리한다.
template<typename T> struct remove_pointer<T>
{
	using type = T;	
};

int main()
{
	remove_pointer<int*>::type n2;	// int* 에서 포인터를 제거한 타입 이므로
									// int n2
}

template<typename T> void foo(T a)
{
	// 주의 !! 
	remove_pointer<int*>::type n1; // T 에 의존하지 않습니다. typename 필요 없습니다
	remove_pointer<T>::type n2;    // T 에 의존합니다.   error  typename 필요 합니다

	typename remove_pointer<T>::type n3;  //  ok..
}