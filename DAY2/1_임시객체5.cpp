#include <iostream>
// 85 page
struct Base
{
	int value = 10; // c++11 ���� �̷��� �ʱ�ȭ����
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;

	std::cout << d.value << std::endl; // 20

	// �Ʒ� 2���� �������� ?
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
	std::cout << static_cast<Base>(d).value << std::endl; // 10

			// => �� ĳ������ "���纻 �ӽð�ü"�� �����ϰ� �˴ϴ�.

	static_cast<Base>(d).value = 30; // error
	static_cast<Base&>(d).value = 30; // ok

}
// �ӽ� ��ü
// 1. ����ڰ� �ǵ������� ����⵵ �ϰ�
//    ex) foo( Point(1,2)) ó�� �Լ����ڷ� ������

// 2. ����ڰ� �ۼ��� �ڵ��� ����� �����Ǳ⵵ �մϴ�.
//   A. ��Ÿ������ ��ȯ�ϴ� �Լ�  ex) Point f1() { return pt;}
//   B. ��Ÿ������ ĳ���� (���ڵ� ����)










