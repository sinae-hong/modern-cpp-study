// move13
#include <iostream>
#include <string>

// const 와 move - 105page
// 핵심 1. 상수 객체는 move 될수 없다.
//      2. 상수 객체에 std::move() 사용시 복사 생성자 호출.

int main()
{
//	std::string s1 = "hello";

	const std::string s1 = "hello";

	std::string s2 = std::move(s1);
					// static_cast< s1타입&&>(s1)
					// static_cast< std::string &&>(s1)  처럼 되었다면 move 생성자 호출
					
					// 그런데, s1 은 "const string" 이므로!
					// static_cast< const std::string &&>(s1)  의 캐스팅이다
					//									이 표현은 아래 2번 호출

	// string의 move 생성자 모양 : string(string&&) {}			1
	// string의 copy 생성자 모양 : string(const string&) {}		2

	std::cout << s1 << std::endl;

}




