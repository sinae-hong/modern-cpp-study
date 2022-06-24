#include <iostream>
#include <type_traits>

// std::enable_if< bool 값, 타입>::type 

// 아래 템플릿은 "정수가 아니면 에러가 아니라" "사용하지 않겠다는 의미"
template<typename T> 
//typename std::enable_if< std::is_integral_v<T>, T>::type	// 조건이 참이면 ::type 은 "T" => 리턴타입 T
											    // 조건이 거짓이면 "::type" 은 없다. 

std::enable_if_t< std::is_integral_v<T>, T>    // _t 버전은 "::type" 표기 안함
gcd(T a, T b)
{
	return 0;  
}



double gcd(double a, double b)
{
	std::cout << "실수 전용 버전" << std::endl;
	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f);
}