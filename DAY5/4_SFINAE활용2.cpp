#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
	std::string addr;
public:
	// �Ʒ� �ڵ��϶� �����޼��� Ȯ��
	/*
	template<typename T1, typename T2>
	People(T1&& s1, T2&& s2)
		: name(std::forward<T1>(s1)), addr(std::forward<T2>(s2))  // ok.. ����!
	{
	}
	*/
	// �����ڴ� "��ȯŸ���� �����ϴ�."
	// enable_if �� ��ȯ Ÿ���ڸ��� ����Ҽ� �����ϴ�.
	// �� ���� "��κ� ���ø� ����" �� �����մϴ�.
	template<typename T1, 
		     typename T2,
//	         typename T3  = std::enable_if_t< ���� > >
			 typename     = std::enable_if_t< std::is_convertible_v<T1, std::string > &&
										     std::is_convertible_v<T2, std::string > > >
	People(T1&& s1, T2&& s2)
		: name(std::forward<T1>(s1)), addr(std::forward<T2>(s2))  // ok.. ����!
	{
	}

	// �Ʒ� ó�� �ϱ⵵ �մϴ�.
	template<typename T = std::enable_if_t<����>,   // �Ǵ�
			 std::enable_if_t<����, int> = 0>
// 
//	������ ���̸� "template<int N = 0>" �� ����Դϴ�.
// ������ �����̸� "template< enable_if<����>::type = 0> ���� "::type" �����Ƿ� ����
};


int main()
{
	std::vector<int> v;
	std::string s1 = "kim";
//	People p1(s1, s1);
	People p1(s1, v);

	std::pair<int, int> p;
}
















