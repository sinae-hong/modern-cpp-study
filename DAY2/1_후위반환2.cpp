#include <iostream>

template<typename T>
T Mul(T a, T b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(1,   2)   << std::endl;
	std::cout << Mul(1.1, 2.2) << std::endl; 

	std::cout << Mul<double>(1, 2.2) << std::endl; // ok
	std::cout << Mul(1, 2.2) << std::endl;			// error
}


