// 20_타입추론1 - 69 page
// 타입 추론 문법

int main()
{
	int x[3] = { 1,2,3 };

	auto n = x[0]; // "int n = x[0]" 으로 컴파일 시간에 결정

	int& r = n;

	auto a = r; // 어떻게 타입이 결정되었을까요 ?
				// 1. int& a = r;
				// 2. int  a = r;

	// 컴파일러가 타입을 결정하는 과정 
	// => type deduction(C++ 진영) 또는 type inference(swift 등 일부언어) 라고 합니다.
	// 타입 추론(연역)이 발생하는 경우
	// 1. auto
	// 2. template - foo(10) => foo가 함수 템플릿이면 인자 10 으로 타입 결정
	// 3. decltype

	// 1, 2는 동일 알고리즘사용
	// 3번은 다른 알고리즘
}




