#include <iostream>

// Step2. ��� �Ѱ� �����ϱ�

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

// tuple ���� Ÿ���� �Ѱ��̻� ������ ��츦 ���� �κ� Ư��ȭ
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value(v) {}

	static constexpr int N = 1;
};

int main()
{
	tuple<> t0;
	tuple<short> t1;		// short �Ѱ� ����
	tuple<double, short> t2;// double �Ѱ� ����
	tuple<int, double, short> t3; // int �Ѱ� ����
}



