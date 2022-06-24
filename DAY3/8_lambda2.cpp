#include <iostream>
#include <algorithm>
#include <vector>
// find_if 의 3번째 인자는 "단항함수"가 요구 됩니다.
// 단항함수 : 인자가 한개인 함수
bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	
	// 주어진 구간에서 3을 찾고 싶다.
	auto ret1 = std::find(v.begin(), v.end(), 3); 
	

	// 주어진 구간에서 "3의 배수를" 찾고 싶다.
	// std::find    : 주어진 구간에서 "값" 검색 - 3번째 인자로 "값" 전달
	// std::find_if : 주어진 구간에서 "조건" 검색 - 3번째 인자로 "함수" 전달
	auto ret2 = std::find_if(v.begin(), v.end(), foo ); 

	int k;
	std::cin >> k;

	// 주어진 구간에서 처음 나오는 "k"의 배수를 찾고 싶다.
	auto ret3 = std::find_if(v.begin(), v.end(), ? ? ? );

	// 람다 표현식 사용하지 말고, 위 문제 해결해 보세요  
	// 답은 "closure" 라는 용어의 뜻을 찾아보세요.- 내일 수업

	// 람다가 이문제를 해결(+추가 장점) 하기 위해 나온 개념
}











