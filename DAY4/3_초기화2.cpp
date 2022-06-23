#include <complex>

int main()
{
	/*
	int n1 = 10;
	int n2(10); 
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);
	*/

	// C++11. 일관된 초기화(uniform initialization) 이라는 문법
	// 모든 종류의 변수를 "동일한 방식" 으로 초기화 할수 있다.
	// 중괄호(brace-init) 초기화 라고도 합니다.
	int n1 = { 10 };
	int x1[2] = { 1,2 };
	std::complex<double> c1 = { 1, 2 };

	// = 이 없어도 됩니다.
	int n2 { 10 };
	int x2[2] { 1,2 };
	std::complex<double> c2 { 1, 2 };

	// direct(직접) initialization : = 이 없는것
	// copy(직접)   initialization : = 이 있는것

}












