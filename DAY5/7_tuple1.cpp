// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);

	// pair 는 3개도 보관가능합니다.
	std::pair<int, std::pair<int, short>> p2(1, std::pair<int, short>(1, 2));

	// 서로다른 타입을 여러개 보관가능하고, 선형적으로 사용가능한 도구
	// C++11 tuple
	std::tuple<int, double, char> t3(1, 3.4, 'A');


	std::get<0>(t3) = 100;

	int n = std::get<0>(t3);
}
// 서로다른 타입을 3개 반환하고 싶다.
auto f()
{
	std::tuple<int, double, char> t3(1, 3.4, 'A');
	return t3;
}




