#include <iostream>

// 129 page
// 함수 객체(function object)
// => () 연산자를 재정의해서 함수 처럼 사용가능한 객체
// => functor 라고도 합니다.

// 함수를 사용하면 되는데,, 왜 함수 객체를 사용합니까 ?
// => 장점이 아주 많습니다.
struct plus
{
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

int main()
{
	plus p;	// p 는 함수가 아닌 객체 입니다.	

	int n1 = p(1, 2); // p 가 함수 처럼 사용됩니다.
	int n2 = p.operator()(1, 2); // 위 한줄의 원리가 이 코드 입니다.

	// a + b => a.operator+(b)
}



