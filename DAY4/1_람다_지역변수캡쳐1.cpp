// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 1. 람다표현식에서 전역변수 - ok.. 사용할수 있다.
	auto f1 = [](int a) { return a + g; };
}





