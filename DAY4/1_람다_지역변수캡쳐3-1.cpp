// 6_����_��������ĸ��1 - 146
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	auto f1 = [v1, v2](int a)         { v1 = 100;  return a + v1 + v2; }; 
	auto f2 = [v1, v2](int a) mutable { v1 = 100;  return a + v1 + v2; };
	auto f3 = [&v1, &v2](int a) { v1 = 100;  return a + v1 + v2; };

	f3(0); 
	std::cout << v1 << std::endl; //  100

	/*
	// �� �ڵ��� ����
	class CompilerGeneratedName
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b)

		int operator()(int a) const
		{
			v1 = 100;	// v1�� ���� �����̹Ƿ�
						// v1�� �����ϴ� ���� �ƴ϶�
						// v1�� ����Ű�� ���� �����Ѱ�
			return a + v1 + v2;
		}
	};
	auto f3 = CompilerGeneratedName(v1, v2);
	*/


}





