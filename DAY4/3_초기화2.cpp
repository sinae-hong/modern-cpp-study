#include <complex>

int main()
{
	/*
	int n1 = 10;
	int n2(10); 
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);
	*/

	// C++11. �ϰ��� �ʱ�ȭ(uniform initialization) �̶�� ����
	// ��� ������ ������ "������ ���" ���� �ʱ�ȭ �Ҽ� �ִ�.
	// �߰�ȣ(brace-init) �ʱ�ȭ ��� �մϴ�.
	int n1 = { 10 };
	int x1[2] = { 1,2 };
	std::complex<double> c1 = { 1, 2 };

	// = �� ��� �˴ϴ�.
	int n2 { 10 };
	int x2[2] { 1,2 };
	std::complex<double> c2 { 1, 2 };

	// direct(����) initialization : = �� ���°�
	// copy(����)   initialization : = �� �ִ°�

}












