// 5_range_for1.cpp   21 page
// cppinsights.io
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

	auto p1 = v.begin(); // std::begin(v) 처럼 할수도 있습니다. 컴파일러마다 다름.
	auto p2 = v.end();

	for (; p1 != p2; ++p1)
	{
		auto& n = *p1;
		//----------------------------
		std::cout << n << std::endl;
	}
}






/*
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = std::vector<int, std::allocator<int> >{ std::initializer_list<int>{1, 2, 3, 4, 5}, std::allocator<int>() };
	{
		std::vector<int, std::allocator<int> > & __range1 = v;

		__gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int> > > __begin1 = __range1.begin();
		__gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int> > > __end1 = __range1.end();
		
		for (; __begin1 != __end1; ++__begin1) 
		{
			int & n = __begin1.operator*();
					// *__begin1;
			std::cout.operator<<(n).operator<<(std::endl);
		}

	}
	return 0;
}
*/







