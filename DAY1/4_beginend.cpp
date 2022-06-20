// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	int x[5] = { 1, 2,3,4,5 };

	// auto : 우변의 표현식을 좌변의 타입을 결정해 달라.
	//		  컴파일 시간에 결정
	auto n = x[0]; // "int n = x[0]"


//	std::vector<int> v = { 1,2,3,4,5 };
//	std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// 1. C++98 시절에 반복자를 꺼내는 코드
	//  단점 : 컨테이너 변경시 "좌변의 반복자 타입을 변경"해야 한다.
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// 2. C++11 부터는 "반복자 타입을 정확히 명시하지말고 auto 사용"을 권장합니다
//	auto p1 = v.begin();
//	auto p2 = v.end();	// error. raw array 는 멤버함수가 없습니다.

	// 3. 컨테이너 뿐 아니라 raw array 도 고려 대상이라면
	//	  멤버 함수 보다 일반함수 "begin" 이 좋다
	auto p1 = std::begin(v);
	auto p2 = std::end(v);  // v 가 raw array 인 경우는 "int* p2"
}