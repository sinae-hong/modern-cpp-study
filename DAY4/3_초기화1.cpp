// 8_�ʱ�ȭ - 55 page
#include <iostream>

int x = 10;

class Test
{
	// Ŭ���� ���鶧 ��� ����Ÿ ���� ���� �ʱⰪ ������ �ֽ��ϴ�.
	int value1 = 0;
	int value2 = ++x;	// �� ��ġ���� ���� �̷��� ������� ������.. ȥ�������� ���ϴ�.
						// ��ó�� "���ͷ���(0)" ���� �ʱ�ȭ�� ����ϼ���.
public:	
	Test()
	{}
	Test(int n) : value2(n) 
	{}
};
/*
// �����Ϸ��� �� �ڵ带 �Ʒ� ó�� �����մϴ�.
class Test
{
	int value1;// = 0;
	int value2;// = ++x;
public:
	// ���� ��� �ʱ�ȭ ����� ���� �����ڸ� �����մϴ�.
	// ����� �ڵ�			// �����Ϸ��� ������ �ڵ�
	Test()					// Test() : value1(0), value2(++x)
	{}
	Test(int n) : value2(n)	// Test(int n) : value(0), value(n) 
	{}
};
*/
int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // �����غ�����. ?
}