// 9_�Ϻ�������_���ǻ���
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

void foo() {}
void foo(int a) {}
void foo(int a, int b) {}

int main()
{
	// �Լ��� ���� ȣ���
	// => ���ڸ� ���� ��� �Լ����� ã���� �ִ�.
	foo();
	foo(10);
	foo(10, 20);

//	printf("%p\n", &foo);	// error
							// foo�� 3���ִµ�, ��� �Լ����� �˼� �����ϴ�.
	printf("%p\n", static_cast<void(*)(int)>(&foo) );
 
//	chronometry(foo, 10); // error. ��� foo ���� �˼� ����

	chronometry(static_cast<void(*)(int)>(&foo), 10); // ok
}









