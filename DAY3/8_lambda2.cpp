#include <iostream>
#include <algorithm>
#include <vector>
// find_if �� 3��° ���ڴ� "�����Լ�"�� �䱸 �˴ϴ�.
// �����Լ� : ���ڰ� �Ѱ��� �Լ�
bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	
	// �־��� �������� 3�� ã�� �ʹ�.
	auto ret1 = std::find(v.begin(), v.end(), 3); 
	

	// �־��� �������� "3�� �����" ã�� �ʹ�.
	// std::find    : �־��� �������� "��" �˻� - 3��° ���ڷ� "��" ����
	// std::find_if : �־��� �������� "����" �˻� - 3��° ���ڷ� "�Լ�" ����
	auto ret2 = std::find_if(v.begin(), v.end(), foo ); 

	int k;
	std::cin >> k;

	// �־��� �������� ó�� ������ "k"�� ����� ã�� �ʹ�.
	auto ret3 = std::find_if(v.begin(), v.end(), ? ? ? );

	// ���� ǥ���� ������� ����, �� ���� �ذ��� ������  
	// ���� "closure" ��� ����� ���� ã�ƺ�����.- ���� ����

	// ���ٰ� �̹����� �ذ�(+�߰� ����) �ϱ� ���� ���� ����
}











