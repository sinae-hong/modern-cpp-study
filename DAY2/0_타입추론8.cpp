// 72page
int x = 10;
int& foo() { return x;  }

int main()
{
	int x[3] = { 1,2,3 };

	// "x[0]" 의 정확한 타입은 "int&" 입니다.
	auto a = x[0]; // int a = x[0];   auto 는 우변의 참조를 버리고 결정하므로

	decltype(x[0]) d = x[0]; // int& d = x[0];

	// 그런데, 위 표기법에는 동일한 표현식 "x[0]" 이 2번 사용됩니다.
	// C++14 부터 "decltype(auto)"등장
	// 우변으로 타입을 결정하는데, 규칙은 "decltype" 규칙 사용
	// 또는, auto 자리에 우변을 넣어 달라.
	decltype(auto) d1 = x[0];
	//--------------------------
	// 아래 ret 변수의 타입을 생각해 보세요
	auto ret1 = foo(); // int ret1 = foo();

	// 리턴 타입을 정확히 만들어서 받으려면
	// decltype(함수호출식) : 함수의 선언을 조사해서 반환 타입을 조사해 달라.
	//						 "함수호출식" 이 실제 실행되는 것은 아님.
	//						=> 평가되지 않은 표현식(unevaluated expression)
	//						   실제로 실행되지는 않는 표현식
	decltype(foo()) ret2 = foo();

	// C++14 부터는 아래처럼 하면 됩니다.
	decltype(auto) ret3 = foo(); // "int& ret3 = foo()"

}





