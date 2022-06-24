// move13
#include <iostream>
#include <string>

// const �� move - 105page
// �ٽ� 1. ��� ��ü�� move �ɼ� ����.
//      2. ��� ��ü�� std::move() ���� ���� ������ ȣ��.

int main()
{
//	std::string s1 = "hello";

	const std::string s1 = "hello";

	std::string s2 = std::move(s1);
					// static_cast< s1Ÿ��&&>(s1)
					// static_cast< std::string &&>(s1)  ó�� �Ǿ��ٸ� move ������ ȣ��
					
					// �׷���, s1 �� "const string" �̹Ƿ�!
					// static_cast< const std::string &&>(s1)  �� ĳ�����̴�
					//									�� ǥ���� �Ʒ� 2�� ȣ��

	// string�� move ������ ��� : string(string&&) {}			1
	// string�� copy ������ ��� : string(const string&) {}		2
	// string(const string&&) {} �̹����� ���� ���ܸ� �������� �ֽ��ϴ�

	std::cout << s1 << std::endl;

}




