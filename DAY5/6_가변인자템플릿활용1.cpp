#include <iostream>

// int n;
// double d;

int f(int a, double b) { return 0; }

// 1. ����ϴ� �ڵ带 ���� primary template ����
template<typename T> struct result
{
	using type = T;
};

// 2. �ٽ� : ���ϴ� Ÿ���� ������ �ֵ��� �κ�Ư��ȭ!!!!! <== ���� �߿�!!

/*
template<typename R, typename A1, typename A2> struct result< R(A1, A2)  >
{
	using type = R;
};
*/
// ���� ������ ������ ������!! �������ڷ�..!
template<typename R, typename ... ARGS> struct result< R(ARGS...)  >
{
	using type = R;
};


template<typename T> void foo(T& a) 
{
	// T : int(int, double) �Դϴ�.
	// �Լ��� ��ȯ Ÿ���� �����ϴ� "result" ���ø��� ����� ���ô�.
	typename result<T>::type n;  // int n

	cout << typeid(n).name() << endl; 
}

int main()
{
	foo(f);
}


