// constexpr 용도 
// 1. constexpr 상수
// 2. constexpr 함수
// 3. constexpr if

int main()
{
	int n = 10;

	const int c1 = n;  // ok 
	const int c2 = 10; // ok

	// C++11 constexpr - "컴파일 시간" 이라는 개념
	constexpr int c3 = n; // error
	constexpr int c4 = 10; // ok
}