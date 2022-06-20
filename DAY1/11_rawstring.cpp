// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	std::string s1 = "\\\\.\\pipe\\server";

	std::cout << s1 << std::endl;


	// Raw String : '\' 를 특수 문자가 아닌 일반 문자로 출력해 달라.
	// "정규표현식", "복잡한 파일 경로"
//	std::string s2 = R"(\\.\pipe\server)";

	// 1. " 를 표기 하려면 - 그냥 적으면 된다. 
	// 문자열 시작 : "(
	// 문자열 종료 : )"
//	std::string s2 = R"(\\.\pi"pe\server)";

	// 2. )" 를 표기하고 싶다.
//	std::string s2 = R"(\\.\pi)"pe\server)"; // error


	// 해결책 -시작기호와 종료 기호를 변경할수있다.
	std::string s2 = R"***(\\.\pi)"pe\server)***"; // ok



	std::cout << s2 << std::endl;
}