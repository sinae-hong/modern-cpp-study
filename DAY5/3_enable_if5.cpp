#include <iostream>
#include <type_traits> 


template<typename T> 
std::enable_if_t< std::is_pointer_v<T>>
printv(const T& v)
{
	// 포인터 일때
	std::cout << v << " : " << *v << std::endl;  
}

template<typename T> 
std::enable_if_t< !std::is_pointer_v<T> >
printv(const T& v)
{
	// 포인터가 아닐때
	std::cout << v << std::endl
}





int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

