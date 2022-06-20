// 8_nullptr2
#include <iostream>

// 왜 nullptr을 만들었나 ?
void foo(int* p)   { std::cout << "int*" << std::endl; }

template<typename F, typename T>
void logAndCall(F f, T arg)	// int arg = 0
{							// std::nullptr_t arg = nullptr;
	// logging 하고
	f(arg);
}
int main()
{
	int n = 0;
	foo(0); // ok.  리터럴 0 만 포인터로 변환되고
//	foo(n); // error. 0을 가진 정수형 변수는 포인터 변환 안됨

//	logAndCall(foo, 0); // 의도는 foo(0), 하지만 error
						// T arg = 0 에서 0으로 추론하므로
						// int arg = 0
						// foo(arg) 이므로 error
	logAndCall(foo, nullptr);
}







