#include <iostream>

int f(int, double, char) { return 0; }

template<int N, typename T> struct argument
{
	using type = T;
};

// 원하는 결과를 찾을수 있도록 부분 특수화
// => 아래 처럼하면 N 번째 인자 타입 구할수 없습니다... 잘못된 부분 특수화
/*
template<int N, typename R, typename ... Types> 
struct argument<N, R(Types...)>
{
	using type = ??;
};
*/
// N == 0 일때 먼저 처리
/*
template<typename R, typename ... Types>
struct argument<0, R(Types...)>
{
	using type = "R(Types...)" 함수의 0번째 인자 타입은 ??
};
*/
// N ==0 성공
template<typename R, typename T, typename ... Types>
struct argument<0, R(T, Types...)>
{
	using type = T;
};

// N != 0 일때..
template<int N, typename R, typename T, typename ... Types>
struct argument<N, R(T, Types...)>
{
	using type = typename argument<N-1, R(Types...)>::type;
};


template<typename T> void foo(T& t)
{
	// T : int(int, double, char)
	typename argument<1, T>::type n; // double n;

	std::cout << typeid(n).name() << std::endl; 
}

int main()
{
	foo(f);
}