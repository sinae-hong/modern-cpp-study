#include <iostream>
#include <algorithm>
#include <vector>

bool foo(int n) { return n % 3 == 0; }


class IsMod
{
	int value;
public:
	IsMod(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0;
	}
};



int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k;
	std::cin >> k;

	// �־��� �������� ó�� ������ "k"�� ����� ã�� �ʹ�.
	// => �Ʒ� ó�� "�Ϲ��Լ��� �����ϸ�, main �ȿ� �ִ� �������� k�� ���� �����Ҽ�����"
	// => "�Լ� + main�� ��������" �� ���� ���� �Ҽ� ������ ?
//	auto ret1 = std::find_if(v.begin(), v.end(), foo );

//	IsMod f(k);
//	auto ret1 = std::find_if(v.begin(), v.end(), f );

	// �ѹ��� ���ȴٸ�, �ӽð�ü�� �����ϴ� ���� ����.
	// => �ᱹ, IsMod �Լ� ��ü�� ����ϸ�
	// => "���������� ĸ�� �Ҽ� �ִ� �����Լ�"�� ����°�
	auto ret1 = std::find_if(v.begin(), v.end(), IsMod(k) );
}











