// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	for (auto& n : v) 
	{
		std::cout << n << std::endl;
	}
	//-------------------
	// 위 코드를 컴파일러가 아래 처럼 변경합니다.

	auto p1 = v.begin();
	auto p2 = v.end();

	for (; p1 != p2; ++p1)
	{
		auto& n = *p1;
		//----------------------------
	}
}















