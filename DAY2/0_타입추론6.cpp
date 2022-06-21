// decltype 타입 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// auto 는 우변의 표현식으로 타입 추론
//	auto a1 = r; // 
//	auto a2;	 // error. 반드시 우변이 필요 하다.

	// decltype : ( ) 안의 표현식으로 타입 추론

	// 규칙 1. ( ) 안에 "심볼의 이름"만 있는 경우
	// => 해당 심볼의 선언을 보고, 동일하게 결정

	decltype(n) d1; // int d1;
	decltype(r) d2; // int& d2;   그런데, 초기값 없으므로 에러
	decltype(c) d3; // const int d3;  초기값 없으므로 에러
	decltype(p) d4; // int* d4;
}



