#include <iostream>
// 85 page
struct Base
{
	int value = 10; // c++11 부터 이렇게 초기화가능
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;

	std::cout << d.value << std::endl; // 20

	// 아래 2줄의 차이점은 ?
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
	std::cout << static_cast<Base>(d).value << std::endl; // 10

			// => 값 캐스팅은 "복사본 임시객체"를 생성하게 됩니다.

	static_cast<Base>(d).value = 30; // error
	static_cast<Base&>(d).value = 30; // ok

}
// 임시 객체
// 1. 사용자가 의도적으로 만들기도 하고
//    ex) foo( Point(1,2)) 처럼 함수인자로 보낼때

// 2. 사용자가 작성한 코드의 결과로 생성되기도 합니다.
//   A. 값타입으로 반환하는 함수  ex) Point f1() { return pt;}
//   B. 값타입으로 캐스팅 (위코드 참고)










