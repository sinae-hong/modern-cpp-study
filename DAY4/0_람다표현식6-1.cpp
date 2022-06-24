#include <functional>

template<typename T> void f1(T f)   { f(1, 2);}

template<typename T> void f2(T&& f) { f(1, 2);}

int main()
{
	std::less<int> f;
	// 아래 처럼 사용했습니다. f1 함수는 몇개 생성될까요 ?
	f1(f);					// f1(std::less<int> )
	f1(std::less<int>());	// f1(std::less<int> )

	f2(f);					// f1(std::less<int>& )
	f2(std::less<int>());	// f1(std::less<int>&& )

}