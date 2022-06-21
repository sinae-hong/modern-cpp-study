// decltype 규칙 2.

int x = 10;

int  f1() { return x; } // x라는 변수가 아닌 x 가 가진 값(10) 반환
int& f2() { return x; } // x의 별명을 반환

int main()
{
	// 핵심 : 함수 호출을 등호의 왼쪽에 놓으려면 "reference" 를 반환해야 합니다.
//	f1() = 20; // error.  10 = 20 의 표기법
//	f2() = 20; // ok..    x = 20 의 표기법


	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	// 규칙 2. () 안에 "심볼의 이름 + 연산자등"을 포함함 표현식이 있을때
	// => 해당 표현식이 등호의 왼쪽에 올수 있으면 "reference"
	// =>					  왼쪽에 올수 없으면 "value 타입"
	decltype(p)		d1; // 규칙 1. int* d1;
	decltype(*p)	d2; // 규칙 2. "*p = 값" 처럼 왼쪽에 올수 있는 표현식
					    // 따라서, "int& d2"
						// 그런데, 초기값 없으므로 에러
	
	decltype(x[0])	d3; // int& d3;     "x[0] = 10" 처럼 왼쪽에 올수 있는 표현식

	auto a = x[0];  // x[0] 은 "int&" 이다.
					// 그런데, "auto" 이므로 우변의 reference를 제거하고 결정
					// 그래서, "int a = x[0]"이 된다.


	decltype(n) d; // "n = 값" 이 되니까, int& 아닌 가요 ???
					// 아닙니다.
					// 심볼의 이름만 있으므로 "규칙 1"을 적용합니다.
					// n의 선언을 보고 타입 결정
					// "int d"
					

	decltype(n + n) d4; // "n+n = 10" 에러이다.. "int d4"
	decltype(++n)   d5; // "++n = 10" 됩니다. ++의 반환값은 값을 증가후
						//					증가된 자신(메모리)를 반환합니다
						//					그래야, "++++n1" 이 가능합니다.
						// int& d5;  초기값 없으므로 에러.
						
	decltype(n++)   d6; // "n++ = 10" 는 안됩니다.
						// int d6;
			
	int k = 3;
	++k; // operator++(k) 호출
	k++; // operator++(k, int) 호출. int 는 전위형과 구별하기 위해 사용하는
		 //						의미 없는 인자
}
/*
// ++ 을 함수 처럼 생각하면 이해하기 쉽습니다.
// => int 타입에 대한 operator++ 을 만들수는 없습니다. 아래코드는 개념설명을 위해
int& operator++(int& n)
{
	n = n + 1;
	return n;
}

int operator++(int& n, int)
{
	int temp = n; // 증가하기 이전값 꺼내 놓고
	n = n + 1;	  // 증가
	return temp;  // 이전값 반환
				// temp 는 파괴되므로 참조 반환 안됩니다.
				// 그래서, temp 가 가진 "값" 을 반환하게 됩니다
}
*/



