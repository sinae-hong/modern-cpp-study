// decltype Ÿ�� �߷� - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// auto �� �캯�� ǥ�������� Ÿ�� �߷�
//	auto a1 = r; // 
//	auto a2;	 // error. �ݵ�� �캯�� �ʿ� �ϴ�.

	// decltype : ( ) ���� ǥ�������� Ÿ�� �߷�

	// ��Ģ 1. ( ) �ȿ� "�ɺ��� �̸�"�� �ִ� ���
	// => �ش� �ɺ��� ������ ����, �����ϰ� ����

	decltype(n) d1; // int d1;
	decltype(r) d2; // int& d2;   �׷���, �ʱⰪ �����Ƿ� ����
	decltype(c) d3; // const int d3;  �ʱⰪ �����Ƿ� ����
	decltype(p) d4; // int* d4;
}



