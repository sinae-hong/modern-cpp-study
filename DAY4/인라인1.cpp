// �ζ���1.cpp - 136 page �̾߱�.

	   int add1(int a, int b) { return a + b; }
inline int add2(int a, int b) { return a + b; }

// 1. �ζ��� ġȯ�� ������ �ð��� �̷�� ����.
// 2. �ζ��� �Լ��� �Լ� �����Ϳ� ��Ƽ� ����ϸ� ġȯ �ɼ� ����.
int main()
{
	int n1 = add1(1, 2); // ȣ�� 
	int n2 = add2(1, 2); // ġȯ

	int(*f)(int, int) = &add2;

//	if (������Է� == 1) f = &add1;

	f(1, 2); // ȣ�� ? ġȯ ?
}