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
	auto end()   { return cont.end(); }
};
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 3);

	for (auto e : tv)
		std::cout << e << std::endl;


}