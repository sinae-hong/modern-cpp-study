#include <iostream>
#include <type_traits>

// 참고 : C++ 표준에는 "remove_all_pointer" 는 없습니다.

template<typename T> struct remove_all_pointer
{
	using type = T;
};
template<typename T> struct remove_all_pointer<T*>
{
//	using type = T;
	// 재귀 사용.
	// 재귀의 종료는 "T=int" 가 될때.. 더이상 부분 특수화 버전을 사용하지 않고
	//              primary 버전을 사용하게 됩니다.
	using type = typename remove_all_pointer<T>::type;
};

int main()
{
	// 아래 traits 는 포인터를 한개 제거 합니다.
	std::remove_pointer<int***>::type n1; // int** n1

	// 포인터를 모두 제거하는 것을 만들어 봅시다.
	remove_all_pointer<int***>::type n2; // int n2
}


