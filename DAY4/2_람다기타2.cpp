#include <iostream>

//void foo(auto n) {} 

int main()
{
	// 151. generic lambda
	auto f = [](int a, int b) { return a + b; };

	int    n = f(1, 2);
	double d = f(3.2, 3.2);


	// C++14, generic lambda, 람다표현식 인자로 auto 사용하는 문법
	auto f1 = [](auto a, auto b) { return a + b; };

	std::cout << f1(1, 2) << std::endl;     // 3
	std::cout << f1(1.1, 2.2) << std::endl; // 3.3
	std::cout << f1(1,   2.2) << std::endl; // 3.2

	// 원리 - 인자가 서로 다른 템플릿으로.. 
	class CompilerGeneratedName
	{
	public:
		template<typename T1, typename T2>
		auto operator()(T1 a, T2 b) const
		{
			return a + b;
		}
	};

	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										a = std::move(b); b = std::move(tmp); };

	int n1 = 10;
	double d1 = 3.4;
	swap(n1, d1); //되는게 좋으세요.. 안되는게 좋으세요 ?
				// 안되는게 좋습니다..
				// 그런데, 지금은 됩니다!!

	// C++14 generic lambda : 모든 인자가 다른 템플릿
	// C++20 template lambda 가 도입됩니다
//	auto swap2 = []<typename T>(T& a, T& b) { T tmp = a; a = b; b = tmp; };

//	swap2(n1, n2); // error
}






