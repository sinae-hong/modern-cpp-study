// C++98 초기화의 문제점 - 54 page
#include <complex>

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int n2(10);  // C 는 안되지만, C++은 이 표기법 가능합니다.
	
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);



	// 2. 동적 할당한 배열을 초기화 할수 없다.
	int* p = int[3];
}



class Test
{
	// 3. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	int x[3];
};

// 4. STL vector 등을 사용시 1~9 등으로 초기화 안됩니다.
std::vector<int> v1(10, 5); // 10개를 5로 초기화, 그런데, 1~10으로 초기화하려면 ?



