#include <iostream>
#include <type_traits>

template<typename T> struct is_pointer
{

	// 왜 enum 상수를 사용합니까 ?
	// bool value = false; // 1. C++11 이전에는 이렇게 초기화 안되고..
						   // 2. 이경우 변수 이므로 컴파일 시간에 결과를 사용할수 없다
	
	// 그래서, C++11 이전에는 아래 방법 밖에 없었습니다.
//	enum { value = false };

	// 그런데, 요즘은 enum 대신 아래 방법으로 합니다.
	static constexpr bool value = false;
};

template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};


template<typename T> void foo(const T& a)
{

	if (is_pointer<T>::value)
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}






int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}