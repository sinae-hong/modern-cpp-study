// 1_�ʱ�ȭ8 - 62page
#include <iostream>
#include <initializer_list> // �ٽ�

void foo(std::initializer_list<int> e)
{
	// �������� STL �� ����
	auto p1 = e.begin();
	autp p2 = e.end();

	// �Ǵ� range-for
	for (auto n : e)
		std::cout << n << std::endl;
}
int main()
{
	// �캯�� ����Ÿ�� "���ÿ� ���ʴ�� ���̰� �˴ϴ�."
	// initializer_list �� {�����ּ�, ����} �� �����մϴ�
	// �Ǵ� {�ּ�, �����������ּ�} �� �����Ҽ��� �ֽ��ϴ�.(�����Ϸ����� �ٸ�)
	std::initializer_list<int> e = { 1,2,3,4,5 };
//	std::vector<int> v = { 1,2,3,4,5 }; // ����Ÿ�� ���� �ֽ��ϴ�.

	foo(e);				// ok
	foo({ 1,2,3,4,5 }); // ok
	foo({ 1,2,3,4,5,6,7,8,9,10 }); // ok
		// ��� : �Լ��� std::initializer_list �� ���ڷ� ������
		//        ���� Ÿ���� ��ü�� ���(����) ������ �ִ�.
}


