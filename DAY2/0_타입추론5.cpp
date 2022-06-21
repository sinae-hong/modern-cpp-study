// 20_Ÿ���߷�5

template<typename T> void foo(T a) {}

int main()
{
	// ���ø��� ȣ��� ������ ���ڷ� Ÿ�� �߷�
	foo(10);
	// T arg = 10  �� ǥ���
	// ��, 10�� ������ T�� Ÿ���� �߷�

	// auto �� template �� �߷� ��Ģ�� �����մϴ�.
	//T arg = 10
	auto a = 10;

	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto �߷��� ���ø� �߷а� �����մϴ�.
	// �Ʒ� �� ������ Ÿ���� ������ ������
	// ��Ģ 1. auto(T) �� �� Ÿ���϶� 
	// => �캯(�Լ�����)�� const, volatile, reference ������ auto Ÿ�԰���
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int

	// ��Ģ 2. auto&(T&) �϶�
	// => �캯�� reference �Ӽ��� �����ϰ�, "auto" Ÿ�� ����

	auto& a5 = n; // auto : int			a5 : int&
	auto& a6 = r; // auto : int			a6 : int&
	auto& a7 = c; // auto : const int	a7 : const int&
	auto& a8 = cr;// auto : const int	a8 : const int&


	// auto �� �迭
	int x[3] = { 1,2,3 };

	auto b1 = x;	// 1. int b1[3] = x;	�̷��� ����� �ָ� "������ ����"
					// 2. int* b1 = x;		�׷���, �̷��� �ڵ� ����
					//						auto : int*  b1 : int*

	auto& b2 = x;	// int (&b2)[3] = x;  �Դϴ�. "�迭�� ����Ű�� ����"��� ����

					// auto : int[3]    b2 : int(&)[3]

}








