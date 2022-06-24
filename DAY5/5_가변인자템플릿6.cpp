#include <iostream>

// 233 page �Դϴ�.

// ��Ϳ� ������ ��� ����ϱ�
// �ٽ� : ��� ���ڸ� �������� ��������, �Ѱ��� ������ Ÿ������ �ϼ���


void foo() {} // ����� ���Ḧ ����

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	static int cnt = 0;
	++cnt;

	std::cout << cnt << ", " << value << std::endl;

//	foo(args...);  // foo(3.4, 'A')
				   // foo('A')
				   // foo()

	// C++17 ���ʹ� �Ʒ� �ڵ尡 ���� ���մϴ�. - "���ڰ� ���� foo()" �ʿ� �����ϴ�.
	// => if constexpr ������ C++17 ����.
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

int main()
{
	foo(1, 3.4, 'A'); // value : 1,   args : 3.4, 'A'
}







