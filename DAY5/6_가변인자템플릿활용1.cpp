#include <iostream>

// int n;
// double d;

int f(int a, double b) { return 0; }

// 1. 사용하는 코드를 보고 primary template 설계
template<typename T> struct result
{
	using type = T;
};

// 2. 핵심 : 원하는 타입을 얻을수 있도록 부분특수화!!!!! <== 아주 중요!!

/*
template<typename R, typename A1, typename A2> struct result< R(A1, A2)  >
{
	using type = R;
};
*/
// 인자 갯수에 제한이 없도록!! 가변인자로..!
template<typename R, typename ... ARGS> struct result< R(ARGS...)  >
{
	using type = R;
};


template<typename T> void foo(T& a) 
{
	// T : int(int, double) 입니다.
	// 함수의 반환 타입을 조사하는 "result" 템플릿을 만들어 봅시다.
	typename result<T>::type n;  // int n

	cout << typeid(n).name() << endl; 
}

int main()
{
	foo(f);
}


