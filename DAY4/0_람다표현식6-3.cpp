// 그냥 auto 로 받으면 안되나요 ?

// 함수 인자로 auto 사용해도 되나요 ?
// C++17 까지는 에러 입니다.
// C++20 부터 함수 인자로 auto 사용가능
// => 결국 템플릿 입니다.			// template<typename T>
void foo(auto arg)				// void foo(T arg)			 입니다.
{
}

int main()
{
	auto a1 = 3;	// int a1 = 3
	auto a2 = 3.4;	// double d2 = 3.4

	foo(3);		// foo(int)
	foo(3.4);	// foo(double)
}