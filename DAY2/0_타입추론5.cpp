// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// 템플릿은 호출시 전달한 인자로 타입 추론
	foo(10);
	// T arg = 10  의 표기법
	// 즉, 10을 가지고 T의 타입을 추론

	// auto 와 template 은 추론 규칙이 동일합니다.
	//T arg = 10
	auto a = 10;

	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 동일합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	// 규칙 1. auto(T) 가 값 타입일때 
	// => 우변(함수인자)의 const, volatile, reference 제거의 auto 타입결정
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int

	// 규칙 2. auto&(T&) 일때
	// => 우변의 reference 속성만 제거하고, "auto" 타입 결정

	auto& a5 = n; // auto : int			a5 : int&
	auto& a6 = r; // auto : int			a6 : int&
	auto& a7 = c; // auto : const int	a7 : const int&
	auto& a8 = cr;// auto : const int	a8 : const int&


	// auto 와 배열
	int x[3] = { 1,2,3 };

	auto b1 = x;	// 1. int b1[3] = x;	이렇게 만들어 주면 "컴파일 에러"
					// 2. int* b1 = x;		그래서, 이렇게 코드 생성
					//						auto : int*  b1 : int*

	auto& b2 = x;	// int (&b2)[3] = x;  입니다. "배열을 가리키는 참조"라는 문법

					// auto : int[3]    b2 : int(&)[3]

}








