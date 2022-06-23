// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// 아래 처럼하면 "operator()" 함수가 상수 멤버 함수 입니다.
//	auto f3 = [v1, v2](int a) { v1 = 100;  return a + v1 + v2; }; 

	// 아래 처럼하면 "operator()" 함수가 "상수멤버함수가 아닙니다."
	auto f3 = [v1, v2](int a) mutable { v1 = 100;  return a + v1 + v2; }; 
	
	f3(0); // 이순간 v1 = 100 이 되지만, 복사본만 변경된것, main 지역변수 변경안됩니다.

	std::cout << v1 << std::endl; // 계속 10

	/*
	// 위 코드의 원리
	class CompilerGeneratedName
	{
		// 지역변수를 캡쳐한 람다표현식은 아래처럼 멤버데이타가 추가됩니다
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b)

		int operator()(int a) //const
		{
			v1 = 100;
			return a + v1 + v2;
		}
	};
	auto f3 = CompilerGeneratedName(v1, v2);
	*/


}





