#include <iostream>
#include <vector>

// C++20 부터 아래와 유사한 클래스가 표준에 추가됩니다.
// 잘 생각해 보세요
class take_view
{
	std::vector<int>& cont;
	int count;
public:
	take_view(std::vector<int>& v, int c) : cont(v), count(c) {}

	auto begin() { return cont.begin(); }
	auto end()   { return cont.begin()+count; }
};

class reverse_view
{
	std::vector<int>& cont;
public:
	reverse_view(std::vector<int>& v) : cont(v) {}

	auto begin() { return cont.rbegin(); }
	auto end() { return cont.rend(); };
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 3);

//	for (auto e : tv)
//	for (auto e : take_view(v, 3))  // 임시객체만들어서 사용(내일 1교시)
	for (auto e : reverse_view(v))  
		std::cout << e << std::endl;
}


