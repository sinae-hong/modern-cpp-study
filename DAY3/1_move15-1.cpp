#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
	std::string addr;
public:
	// ���ڰ� 2���� �����ڸ� move �����Ϸ��� "4��"�� �Լ�
	// ���ڰ� N���� �����ڸ� move �����Ϸ��� "2^N"�� �Լ� => �ٸ� ����� ������ ?? ���� ����!!
//	People(const std::string& s1, const std::string& s2) : name(s1), addr(s2) {}
//	People(const std::string& s1, std::string&& s2) : name(s1), addr(std::move(s2)) {}
//	People(std::string&& s1, const std::string& s2) : name(std::move(s1)), addr(s2) {}
//	People(std::string&& s1, std::string&& s2) : name(std::move(s1)), addr(std::move(s2)) {}

	// ���ڰ� 2���̻��ΰ��� ��ó�� �Լ��� �ʹ� �������ϴ�.
	// forwarding reference �� �ϼ���
	template<typename T1, typename T2>
	People(T1&& s1, T2&& s2) 
//		: name(s1), addr(s2)  // <== �׻� ����
//		: name(std::move(s1)), addr(std::move(s2))  // <== �׻� move
		: name(std::forward<T1>(s1)), addr(std::forward<T2>(s2))  // ok.. ����!
	{
	//	name = std::forward<T1>(s1);
	}
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
// 9:35 �� ~ 















