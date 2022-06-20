// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 전통적인 for 문
	for (int i = 0; i < v.size(); i++)
	{
	}

	// C++11 의 새로운 for 문 - range for
//	for (int   e : v )
//	for (auto  e : v)
	for (auto& e : v) // STL 컨테이너 뿐 아니라 배열도 가능
	{
		e = 0; // 이렇게 수정하려면 reference로!
		std::cout << e << ", ";
	}
	std::cout << std::endl;
}

















