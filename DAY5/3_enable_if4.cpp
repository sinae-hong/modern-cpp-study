#include <iostream>
#include <type_traits>

// 현재 C++은 "특정 타입" 에 따른 함수 오버로딩을
// 지원 합니다.
void foo(int)    {}
void foo(double) {}

// "타입"이 아닌 "특정 조건을 만족하는 타입들"에 따른 오버로딩은 있으면
// 좋지 않을까요 ?
//void goo(가상함수가있는클래스들) {}
//void goo(가상함수가없는클래스들) {}

// 반환 타입 자리에 : enable_if_t<조건, 반환타입> 인데..
//					반환 타입 생략시 void 가 적용된다.

template<typename T>
//std::enable_if_t< 가상함수가있는타입, void>
//std::enable_if_t< std::is_polymorphic_v<T>,  void>
std::enable_if_t< std::is_polymorphic_v<T> >
goo(T a)
{
	std::cout << "가상함수가 있는 타입에 대한 알고리즘" << std::endl;
}

template<typename T>
std::enable_if_t< !std::is_polymorphic_v<T> >
goo(T a)
{
	std::cout << "가상함수가 없는 타입에 대한 알고리즘" << std::endl;
}

class A
{
public:
	virtual void f() {}
};

int main()
{
	A a;
	goo(a);
}




