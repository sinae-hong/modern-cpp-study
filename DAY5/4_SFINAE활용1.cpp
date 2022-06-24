// 1_move14-1
#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
	std::string addr;
public:
	// ��� 1. 2�� ������
//	void setName(const std::string& r) { name = r; }
//	void setName(std::string&& r) { name = std::move(r); }

	// ��� 2. forwarding reference

	// �ٽ� : �ڵ尡 �Ʒ��� ������ main ó�� ����. �����޼��� �� Ȯ���ϼ���
	// setName(vector& arg) �Լ��� �����ǰ�
	// "name = arg" �ڵ忡�� ���� �߻�
	/*
	template<typename T>
	void setName(T&& arg)
	{
		name = std::forward<T>(arg);
	}
	*/
	template<typename T>
	
	std::enable_if_t< std::is_convertible_v<T, std::string> >
	setName(T&& arg)
	{
		name = std::forward<T>(arg);
	}

};

int main()
{  
	std::vector<int> v;

	People p;
	
	p.setName("kim");
	p.setName(v);

}















