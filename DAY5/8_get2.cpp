#include <iostream>

// Step3. N개 보관하기 ==> 핵심..

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
	//	tuple<             short> t1;		// short 한개 보관   - 2
	//	tuple<     double, short> t2;		// double 한개 보관  - 3.4
	tuple<int, double, short> t3(1, 3.4, 2);// int 한개 보관     - 1

	std::cout << t3.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short> &>(t3).value << std::endl; // 3.4

	std::cout << static_cast<tuple<short> &>(t3).value << std::endl; // 2


	int n = get<0>(t3);
}
template<int N, typename TP>
N번째 요소 타입&
get(TP& tp)
{
	return static_cast<N번째기반클래스타입&>(tp).value;
}



