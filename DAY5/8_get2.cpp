#include <iostream>

// Step3. N�� �����ϱ� ==> �ٽ�..

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;

	tuple() = default;
	tuple(const T& v, const Types& ... args) : value(v), base(args...) {}

	static constexpr int N = base::N + 1;
};

int main()
{
	//	tuple<> t0;
	//	tuple<             short> t1;		// short �Ѱ� ����   - 2
	//	tuple<     double, short> t2;		// double �Ѱ� ����  - 3.4
	tuple<int, double, short> t3(1, 3.4, 2);// int �Ѱ� ����     - 1

	std::cout << t3.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short> &>(t3).value << std::endl; // 3.4

	std::cout << static_cast<tuple<short> &>(t3).value << std::endl; // 2


	auto n = get<2>(t3);
}
template<int N, typename TP>
N��° ��� Ÿ��&
get(TP& tp)
{
	return static_cast<N��°���Ŭ����Ÿ��&>(tp).value;
}

// ��� get�� �������, ���� tuple��
// 1. N��° ����� Ÿ���� ���Ҽ� �־�� �ϰ�
// 2. N��° ��� Ŭ���� Ÿ���� ���Ҽ� �־�� �Ѵ�.


