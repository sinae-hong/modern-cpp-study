// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : ���� �ٸ� Ÿ�� 2���� ���� - C++98
	std::pair<int, double> p(1, 2.3);

	// pair �� 3���� ���������մϴ�.
	std::pair<int, std::pair<int, short>> p2(1, std::pair<int, short>(1, 2));

	// ���δٸ� Ÿ���� ������ ���������ϰ�, ���������� ��밡���� ����
	// C++11 tuple
	std::tuple<int, double, char> t3(1, 3.4, 'A');


	std::get<0>(t3) = 100;

	int n = std::get<0>(t3);
}
// ���δٸ� Ÿ���� 3�� ��ȯ�ϰ� �ʹ�.
auto f()
{
	std::tuple<int, double, char> t3(1, 3.4, 'A');
	return t3;
}




