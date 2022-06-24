#include <iostream>

int f(int, double, char) { return 0; }

template<int N, typename T> struct argument
{
	using type = T;
};

// ���ϴ� ����� ã���� �ֵ��� �κ� Ư��ȭ
// => �Ʒ� ó���ϸ� N ��° ���� Ÿ�� ���Ҽ� �����ϴ�... �߸��� �κ� Ư��ȭ
/*
template<int N, typename R, typename ... Types> 
struct argument<N, R(Types...)>
{
	using type = ??;
};
*/
// N == 0 �϶� ���� ó��
/*
template<typename R, typename ... Types>
struct argument<0, R(Types...)>
{
	using type = "R(Types...)" �Լ��� 0��° ���� Ÿ���� ??
};
*/
// N ==0 ����
template<typename R, typename T, typename ... Types>
struct argument<0, R(T, Types...)>
{
	using type = T;
};

// N != 0 �϶�..
template<int N, typename R, typename T, typename ... Types>
struct argument<N, R(T, Types...)>
{
	using type = typename argument<N-1, R(Types...)>::type;
};


template<typename T> void foo(T& t)
{
	// T : int(int, double, char)
	typename argument<1, T>::type n; // double n;

	std::cout << typeid(n).name() << std::endl; 
}

int main()
{
	foo(f);
}