#include <iostream>

#include <vector>

// 함수 객체는 동작뿐 아니라 "상태"를 가질수 있습니다(멤버 데이타가 있다는 의미)
// 또한, 생성자/소멸자/복사 생성자 등도 활용가능합니다. 
// 함수 처럼 사용하지만, 함수 보다 기능이 많습니다

class URandom
{
	std::vector<int> history;
public:
	int operator()()
	{
		return rand() % 10;
	}
};
URandom urand; // 객체지만 "operator()" 연산자가 재정의 되어서 함수처럼 사용가능


int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << urand() << std::endl;
	}
}