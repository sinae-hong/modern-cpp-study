#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k;
	std::cin >> k;
	
	// C++11 ���ʹ� ���� ǥ������ ����ϸ� ���մϴ�
	// => "�Լ��̸�(�ּ�)�� ���޵Ǵ� �ڸ��� �Լ� ���� �ڵ带 ���� �ۼ��ϴ� ��"
	// => [] : ���ٰ� ���۵��� �˸��� "lambda introducer" 

	auto ret1 = std::find_if(v.begin(), v.end(), [k](int n) { return n % k == 0; } );

	// �� �ڵ带 ���� �����Ϸ��� �Ʒ� �ڵ�� �����մϴ�.
	class CompilerGeneratedName
	{
		int k;
	public:
		CompilerGeneratedName(int n) : k(n) {}

		bool operator()(int n) const
		{
			return n % k == 0;
		}
	};
	auto ret1 = std::find_if(v.begin(), v.end(), CompilerGeneratedName(k) );

	// �ٽ� : ����ǥ������ 
	// 1. �Լ���ü�� ����� ǥ���� �Դϴ�.(�����Ϸ��� Ŭ���� ����)
	// 2. ����ǥ������ ���� ����� "�ӽð�ü(rvalue)" �Դϴ�.

}











