// 1_move14-1
#include <iostream>
#include <string>
#include <vector>

// 106 page
class People
{
	std::string name;
	std::string addr;
public:
	// ��� 1. 2�� ������
//	void setName(const std::string& r) { name = r; }
//	void setName(std::string&& r) { name = std::move(r); }

	// 107 page
	// ��� 2. forwarding reference �� ����ϸ� string&, string&& ������ �Լ��� �ڵ������Ҽ� �ִ�.
	// => ��, �� 2���� �Լ��� �ڵ������Ҽ� �ִ�.
	template<typename T>
	void setName(T&& arg)
	{
		// ������ �´� ���� ?
//		name = arg;					// 1. �׻� ���� ����
//		name = std::move(arg);		// 2. �׻� rvalue �� ĳ����, ��, �׻� move
		name = std::forward<T>(arg);// 3. setName �� ���ڷ� rvalue �� ���´ٸ� rvalueĳ����
									//                     lvalue �� ���´ٸ� lvalueĳ����
	}

	// ���� - setName()�� ���� �����ص� 2���� �˴ϴ�
	// => ���1. ����ϼ���
};

int main()
{
	People p;

	std::string s1 = "kim";
	std::string s2 = "kim";
	const std::string s3 = "kim";
	char char* s4 = "park";
	//							setName() �� ���ø� �̹Ƿ�
	p.setName(s1);				// setName(std::string& ) ����
	p.setName(s3);				// setName(const std::string& ) ����
	p.setName(s4);				// setName(const char*& ) ����
	p.setName(std::move(s2));	// setName(std::string&& ) ����


	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // "" 

}















