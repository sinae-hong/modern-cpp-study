#include <iostream>

// 2개의 인자가 서로 다른 타입이 될수 있도록
template<typename T1, typename T2>
//?? Mul(T1 a, T2 b)  // ? 를 채우기 어려웠습니다.

//decltype(a * b) Mul(T1 a, T2 b) // 그래서, decltype()을 만들었습니다.
								// => 그런데, 왜 에러일까요 ?
								// => a, b 가 선언전에 사용됩니다.
auto Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(1, 2.2) << std::endl;			

//	a = 20;// error. 변수를 선언전에 사용
//	int a;
//	a = 10; // ok.. 변수를 선언후 사용
}


