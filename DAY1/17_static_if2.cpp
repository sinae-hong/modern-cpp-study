#include <type_traits>

// 17_static_if - 51 page

template<typename T> void foo(T a) 
{
	// 0을 전달받았으면 a는 int 타입
	// int a = 0;

	// if : 실행시간 제어문
	//      조건식이 컴파일 시간에 결정될수 있어도 
	//      실행시간 조사식으로 판단해서, 컴파일 시간에 "false"로 결정되어도
	//		무조건 "템플릿" => "C++코드" 를 생성 
//	if (false)
//		*a = 10;

	// C++17 컴파일 시간 제어문
	//  => 조건식이 false 라면 "템플릿" => "C++코드" 생성 안됨.
//	if constexpr (false)
//		*a = 10;

	// 실전에서는 아래 처럼 하게 됩니다.
	if constexpr (std::is_pointer_v<T>) // T가 포인터 타입일때만
		*a = 10;						// 아래 코드를 생성하겠다

}

int main()
{
	foo(0); 
}
// C++17 사용하려면
// g++ : -std=c++17
// VC  : /std:c++17 또는 /std:c++latest 필요
