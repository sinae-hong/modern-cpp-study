// 8_초기화 - 55 page
#include <iostream>

int x = 10;

class Test
{
	// 클래스 만들때 멤버 데이타 선언에 직접 초기값 넣을수 있습니다.
	int value1 = 0;
	int value2 = ++x;
public:	
	Test()
	{}
	Test(int n) : value2(n) 
	{}
};
/*
// 컴파일러가 위 코드를 아래 처럼 변경합니다.
class Test
{
	int value1;// = 0;
	int value2;// = ++x;
public:
	// 위의 멤버 초기화 모양을 보고 생성자를 변경합니다.
	// 사용자 코드			// 컴파일러가 변경한 코드
	Test()					// Test() : value1(0), value2(++x)
	{}
	Test(int n) : value2(n)	// Test(int n) : value(0), value(n) 
	{}
};
*/
int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // 예측해보세요. ?
}