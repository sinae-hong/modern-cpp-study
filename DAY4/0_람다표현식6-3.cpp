// �׳� auto �� ������ �ȵǳ��� ?

// �Լ� ���ڷ� auto ����ص� �ǳ��� ?
// C++17 ������ ���� �Դϴ�.
// C++20 ���� �Լ� ���ڷ� auto ��밡��
// => �ᱹ ���ø� �Դϴ�.			// template<typename T>
void foo(auto arg)				// void foo(T arg)			 �Դϴ�.
{
}

int main()
{
	auto a1 = 3;	// int a1 = 3
	auto a2 = 3.4;	// double d2 = 3.4

	foo(3);		// foo(int)
	foo(3.4);	// foo(double)
}