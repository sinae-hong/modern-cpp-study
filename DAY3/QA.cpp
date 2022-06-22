#include <iostream>
// 핵심 : 템플릿 보다 일반 함수가 우선 선택된다.
//void foo(int a)
//void foo(int& a)
void foo(int&& a)
{
	std::cout << "int" << std::endl;
}
template<typename T>
//void foo(T a)
void foo(T&& a)
{
	std::cout << "T" << std::endl;
}
int main()
{
	int n = 10;
	// 결과 확인해 보세요
	foo(10);  // 일반함수 사용가능 하므로 사용
	foo(n);   // 일반함수 사용안됨(int&& 이므로), 템플릿 사용
//	foo<int>(n);
	foo<>(n);
	foo<>(10);
}


