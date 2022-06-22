#include <iostream>

// 0 ~ 9 사이의 "중복되지 않은" 난수를 반환 하는 함수 (rand() 사용하세요)
// 일반함수는 "동작은 있지만 상태가 없다"
// 함수 연산의 결과를 보관할 곳이 없다.
// 그래서, 전역변수등을 사용하게 된다.
int urand()
{
	return rand() % 10 ;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << urand() << std::endl;
	}
}