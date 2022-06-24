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

template<int N, typename TP> 
struct tuple_element
{
	using type = TP;
};

// N == 0
//template<typename TP> struct tuple_element<0, TP>  // �߸��� ����
//template<typename ... Types> struct tuple_element<0, tuple<Types...> > 
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
};

// N != 0
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type =  typename tuple_element<N-1, tuple<Types...>>::type ;
};



template<typename TP> 
void foo(TP& tp)
{
	// TP : tuple<int, double, short> �Դϴ�.
	typename tuple_element<1, TP>::type n; // double n ���;� �մϴ�.

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	tuple<int, double, short> t3(1, 3.4, 2);

	foo(t3);

}



