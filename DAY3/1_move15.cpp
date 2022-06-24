#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
	std::string addr;
public:
	// �����ڸ� ������ ���ô�.
	// ���ڰ� �Ѱ��� �����ڸ� move �����ϱ� - 2���� ������
	People(const std::string& s) : name(s) {}
	People(std::string&& s) : name(std::move(s)) {}

	// ���ڰ� 2���� �����ڸ� move �����Ϸ��� "4��"�� �Լ�
	// ���ڰ� N���� �����ڸ� move �����Ϸ��� "2^N"�� �Լ� => �ٸ� ����� ������ ?? ���� ����!!
	People(const std::string& s1, const std::string& s2) : name(s1), addr(s2) {}
	People(const std::string& s1, std::string&& s2)      : name(s1), addr(std::move(s2)) {}
	People(std::string&& s1,      const std::string& s2) : name(std::move(s1)), addr(s2) {}
	People(std::string&& s1,	  std::string&& s2)		 : name(std::move(s1)), addr(std::move(s2)) {}
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "seoul";
//	People p1(s1);
//	People p2(std::move(s1));

	People p3(s1, s2);
	People p4(s1, std::move(s2));

}
















