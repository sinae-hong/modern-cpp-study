// 7_�����������ø�7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// �������� ���ø��� ���� �θ� ���Ǵ� ���� �ƴմϴ�.
// �� �ʿ��� ��찡 �ֽ��ϴ�..
// �Ʒ� ����...

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
//	return f( std::forward<Types>(args) ); // error. �Լ��� pack �̸� ���� �ȵ�
//	return f(std::forward<Types>(args...)); //  forward(1,2,n) �� �ǹ�, 
											//�׷��� forward�� ���ڰ� �Ѱ�
	return f(std::forward<Types>(args)... );
			// f( std::forward<int>(1),std::forward<int>(2), std::forward<int&>(n) )
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

