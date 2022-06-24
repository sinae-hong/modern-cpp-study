#include <iostream>
#include <string>

// 왜 move 가 중요한가 ?
template<typename T>
void Swap(T& a, T& b)
{
	// 아래 코드는 "복사"에 의한 swap입니다.
	// 느립니다.
//	T tmp = a;
//	a = b;
//	b = tmp;

	// 아래 코드는 "이동"를 사용한 swap 입니다.
	// 위 코드 보다 빠릅니다.
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}
// "move" 주제에서 알아야 하는것
// 1. 클래스 사용자
//    => swap 같은 알고리즘 작성시 적절히 "std::move" 를 사용하면 
//    => 성능이 향상된다.

// 2. 클래스 제작자
//    => 내가 만든 클래스가 move를 지원하려면 어떻게 해야 하는가 ?
//    => 약간 어려운 이야기!!

// 3:55 분  ~

