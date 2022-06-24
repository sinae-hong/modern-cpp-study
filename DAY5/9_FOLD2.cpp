// 9_FOLD - 237 page
#include <iostream>
#include <vector>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	// (초기값 op ... op pack )
//	(std::cout << ... << args); // (((cout << 1) << 2) << 3)

//	(printv(args), ...);	// , 가 이항 연산자 입니다
							// pack 이름뿐 아니라 pack 을 사용하는 패턴도 가능
							// ((( printv(1) ), printv(2) ), printv(3) )
	std::vector<int> v;

	(v.push_back(args), ...);

	// 구글에서 "C++ fold expression example" 하면 재미 있는 예제 많습니다.
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



