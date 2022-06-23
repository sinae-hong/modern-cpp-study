#include <functional>

template<typename T> void sort(T f)
{
	f(1, 2); 
}

int main()
{
	// sort()를 사용하다 보니 동일한 람다 표현식을 여러번 사용하게 되었습니다.
	// => 질문, sort() 함수는 몇개 생성 되었을까요 ?
	// => 3개
	// => 모든 람다 표현식은 다른 타입 이므로
//	sort( [](int a, int b) { return a < b; } );
//	sort( [](int a, int b) { return a < b; } );
//	sort( [](int a, int b) { return a < b; } );

	// 동일한 람다 표현식이 여러번 사용되면
	// auto 변수에 담아서 사용하세요
	auto f = [](int a, int b) { return a < b; };
	sort(f);
	sort(f);
	sort(f);

	// 동일한 람다표현식이 여러번 필요 하면
	// => 함수객체로 따로 만들거나, C++ 표준에 이미 존재하는 함수 객체 사용하세요
	std::less<int> f2;
	sort(f2);
	sort(f2);
	sort(std::less<int>()); // 이때는  이렇게 해도 됩니다, f2와 같은 타입이므로
}




