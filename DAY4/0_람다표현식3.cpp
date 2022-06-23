#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k;
	std::cin >> k;
	
	// C++11 부터는 람다 표현식을 사용하면 편리합니다
	// => "함수이름(주소)가 전달되는 자리에 함수 구현 코드를 직접 작성하는 것"
	// => [] : 람다가 시작됨을 알리는 "lambda introducer" 

	auto ret1 = std::find_if(v.begin(), v.end(), [k](int n) { return n % k == 0; } );

	// 위 코드를 보고 컴파일러가 아래 코드로 변경합니다.
	class CompilerGeneratedName
	{
		int k;
	public:
		CompilerGeneratedName(int n) : k(n) {}

		bool operator()(int n) const
		{
			return n % k == 0;
		}
	};
	auto ret1 = std::find_if(v.begin(), v.end(), CompilerGeneratedName(k) );

	// 핵심 : 람다표현식은 
	// 1. 함수객체를 만드는 표현식 입니다.(컴파일러가 클래스 생성)
	// 2. 람다표현식의 최종 결과는 "임시객체(rvalue)" 입니다.

}











