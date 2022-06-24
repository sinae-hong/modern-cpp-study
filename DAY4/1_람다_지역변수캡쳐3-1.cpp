// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	auto f1 = [v1, v2](int a)         { v1 = 100;  return a + v1 + v2; }; 
	auto f2 = [v1, v2](int a) mutable { v1 = 100;  return a + v1 + v2; };
	auto f3 = [&v1, &v2](int a) { v1 = 100;  return a + v1 + v2; };

	f3(0); 
	std::cout << v1 << std::endl; //  100

	/*
	// 위 코드의 원리
	class CompilerGeneratedName
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b)

		int operator()(int a) const
		{
			v1 = 100;	// v1이 참조 변수이므로
						// v1을 변경하는 것이 아니라
						// v1이 가리키는 곳을 변경한것
			return a + v1 + v2;
		}
	};
	auto f3 = CompilerGeneratedName(v1, v2);
	*/


}





