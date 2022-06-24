#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// STL �� sort �� ��� ���ڰ� template �Դϴ�
	// 1. ����å���� �Ϲ��Լ��� ������
	// ���� : ����å�� ������ ��ü�ص� sort() �Լ��� �Ѱ��� ����
	//		 �ڵ�޸� ��������
	// ���� : ����å�� �ζ��� ġȯ�ɼ� ����. - ������.

	std::sort(x, x + 10, cmp1);// sort(int*, int*, bool(*)(int, int)) �� �Լ� ����
	std::sort(x, x + 10, cmp2);// sort(int*, int*, bool(*)(int, int)) �� �Լ� ����


	// 2. ����å���� �Լ� ��ü ����
	std::less<int> f1; // �̹� �� �Լ���ü�� C++ǥ�ؿ� �ֽ��ϴ�.
	std::greater<int> f2;

	// ���� : �� ��å�� �ζ��� ġȯ�ȴ�. ������.
	// ���� : �� ��å�� ��ü�� Ƚ�� ��ŭ "sort()" �Լ��� �����ȴ�.
	//		 �ڵ� �޸� ����! => �׷���, sort ���� ��ü�� ũ�� �ʴ�.!!

	std::sort(x, x + 10, f1); // sort(int*, int*, std::less<int>) �� �Լ� ����
	std::sort(x, x + 10, f2); // sort(int*, int*, std::greater<int>) �� �Լ� ����

}


