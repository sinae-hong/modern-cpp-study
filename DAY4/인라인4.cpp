#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// STL 의 sort 는 모든 인자가 template 입니다
	// 1. 비교정책으로 일반함수를 보낼때
	// 장점 : 비교정책을 여러번 교체해도 sort() 함수는 한개만 생성
	//		 코드메모리 증가안함
	// 단점 : 비교정책이 인라인 치환될수 없다. - 느리다.

	std::sort(x, x + 10, cmp1);// sort(int*, int*, bool(*)(int, int)) 인 함수 생성
	std::sort(x, x + 10, cmp2);// sort(int*, int*, bool(*)(int, int)) 인 함수 생성


	// 2. 비교정책으로 함수 객체 사용시
	std::less<int> f1; // 이미 이 함수객체가 C++표준에 있습니다.
	std::greater<int> f2;

	// 장점 : 비교 정책이 인라인 치환된다. 빠르다.
	// 단점 : 비교 정책을 교체한 횟수 만큼 "sort()" 함수가 생성된다.
	//		 코드 메모리 증가! => 그런데, sort 구현 자체가 크지 않다.!!

	std::sort(x, x + 10, f1); // sort(int*, int*, std::less<int>) 인 함수 생성
	std::sort(x, x + 10, f2); // sort(int*, int*, std::greater<int>) 인 함수 생성

}


