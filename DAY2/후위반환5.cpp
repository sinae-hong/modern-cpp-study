// decltype(auto) ���� auto ��ȯ�� �� ������ ��찡 �����ϴ�

auto f1()			// int f1()
{
	int n = 10;
	int* p = &n;
	return *p;
}

decltype(auto) f2()	// int& f2()
{
	int n = 10;
	int* p = &n;
	return *p;
}

auto f3()  // int* f3()   �̹Ƿ� ok..
{
	static int x[3] = { 1,2,3 };
	return x;
}

decltype(auto) f4() // int ( f4())[3]   ��, �迭�� ��ȯ�ϴ� �Լ�
{						//	�׷���, �迭�� ��ȯ�ϴ� �Լ��� ������ ����
	static int x[3] = { 1,2,3 };
	return x;
}

int main()
{

}