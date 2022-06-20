//8_nullptr3
#include <iostream>

void foo(int)    { std::cout << "int" << std::endl; }
void foo(double) { std::cout << "double" << std::endl; }
void foo(bool)   { std::cout << "bool" << std::endl; }
void foo(char*)  { std::cout << "char*" << std::endl; }

int main()
{
	foo(0);   // int.   0 은 정수형(int) 리터럴 이므로
	foo(0.0); // double. 0.0 은 실수형 리터럴 이므로
	foo(false); // bool. false 는 bool 형 리터럴 (키워드)
	foo(nullptr); // char*,  nullptr은 포인터형 리터럴(키워드)

	// 모든 리터럴은 타입이 있습니다
	10; // int
	3.4; // double
	true; // bool
	nullptr; // std::nullptr_t 라는 타입
			 // std::nullptr_t 라는 타입은 모든 종류의 포인터로 암시적 변환 가능

	std::nullptr_t null = nullptr;

	int* p2 = null; // 이제 null은 nullptr 과 동일
}







