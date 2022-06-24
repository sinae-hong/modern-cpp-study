#include <functional>

template<typename T> void sort(T f)
{
	f(1, 2); 
}

int main()
{
	// sort()�� ����ϴ� ���� ������ ���� ǥ������ ������ ����ϰ� �Ǿ����ϴ�.
	// => ����, sort() �Լ��� � ���� �Ǿ������ ?
	// => 3��
	// => ��� ���� ǥ������ �ٸ� Ÿ�� �̹Ƿ�
//	sort( [](int a, int b) { return a < b; } );
//	sort( [](int a, int b) { return a < b; } );
//	sort( [](int a, int b) { return a < b; } );

	// ������ ���� ǥ������ ������ ���Ǹ�
	// auto ������ ��Ƽ� ����ϼ���
	auto f = [](int a, int b) { return a < b; };
	sort(f);
	sort(f);
	sort(f);

	// ������ ����ǥ������ ������ �ʿ� �ϸ�
	// => �Լ���ü�� ���� ����ų�, C++ ǥ�ؿ� �̹� �����ϴ� �Լ� ��ü ����ϼ���
	std::less<int> f2;
	sort(f2);
	sort(f2);
	sort(std::less<int>()); // �̶���  �̷��� �ص� �˴ϴ�, f2�� ���� Ÿ���̹Ƿ�
}




