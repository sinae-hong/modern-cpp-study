#include <iostream>
#include <string>
#include <vector>

// 106 page
class People
{
	std::string name;
	std::string addr;
public:
	// �Լ� ���ڷ� "call by value" ���
	// => ���� Ÿ���� ����� ���� Ÿ���̸� "���纻����"�� ���� ������尡 �ֽ��ϴ�.
	// => �̷��� ���� ���� "const &" �� �ϼ���
//	void setName(std::string s) { name = s; }

	// setter �Լ� ���ڸ� "const reference" �� �ޱ� - C++98 ���� �ְ��� �ڵ�..
	// �׷���, C++11 ���ʹ�....
//	void setName(const std::string& r) { name = r; } // �׻� ����
//	void setName(const std::string& r) { name = std::move(r); } // ���� �׻� ����
														// r �� const �̹Ƿ�!!
														// const �� move�ɼ� ����

	// C++11 ������ �ְ��� "setter �Լ�"
	void setName(const std::string& r) { name = r; }
	void setName(std::string&& r)      { name = std::move(r); }

	// ���ڷ� ���޵Ȱ��� ����� �����ϴ� �뵵(setter) �� �ƴ϶��
	// �׳� �Ѱ� ����� �˴ϴ�
	void fn(const std::string& s)
	{
		// s�� ��븸 �ϴ� ���
		std::cout << s << std::endl;
	}

	// ���� 
	// 1. �׳� ���ڿ��� �޾Ƽ� ��븸 �ϴ� �Լ� => const std::string& ���θ� ��������
	//										�ᱹ, ������ ���纻�� ����� ���� �����Ƿ�
	//										move ����� ��� �ƴմϴ�
	// 2. ���ڷ� ���� ���ڿ��� �ٽ� "�������Ÿ" ���� �����ϴ� ���, setName() ó��
	// => �� ó�� 2�� ���弼��.. => �ּ��� �ڵ�
};

int main()
{
	People p;

	std::string s1 = "kim";
	std::string s2 = "kim";

	p.setName(s1);				// s�ڿ� �����ؼ� ����ض�
	p.setName(std::move(s2));	// s�ڿ� �̵��ؼ� ����ض�

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // "" 


	p.fn(s1);
	p.fn(std::move(s1));

	std::vector<std::string> v;

	std::string s2 = "aaa";

	v.push_back(s2);
	v.push_back(std::move(s2));
}






