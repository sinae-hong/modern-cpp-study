// 6_enable_if1.cpp

// 핵심 1. 템플릿 인자로 타입이 아닌 "값" 도 전달할수 있습니다
//      2. 템플릿 인자의 디폴트 값은 "primary" 에만 표기합니다.
//         부분 특수화 버전은 표기하면 안됩니다.(단, primary 내용대로 적용됩니다.)

template<bool, typename T = void > struct enable_if
{
//	typedef  T type; // 예전 스타일
	using type = T;  // 요즘 스타일
};
template<typename T> struct enable_if<false, T> 
{
};

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2 인데, void는 변수생성 안됨. error
	enable_if<false, int>::type n3; // "::type" 이 없다는 에러

	// 정리하면
	// 1. enable_if<true, 타입>::type 의 결과는 "타입"
	// 2. enable_if<true>::type       의 결과는 "void"

	// 3. enable_if<false, 타입>::type 의 결과는 ?  "::type" 자체가 없다
	// 4. enable_if<false>::type       의 결과는 ?  "::type" 자체가 없다
}

#include <type_traits> // 이 안에 "enable_if" 있습니다. C++ 표준입니다.

template<typename T> void foo(T a)
{
	// T 에 의존해서 사용하면 typename 필요
	typename std::enable_if<true, T>::type n1;

	std::enable_if_t<true, T> n2;  // 이렇게 하면 위와 동일
}




