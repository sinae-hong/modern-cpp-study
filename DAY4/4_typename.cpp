// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// �Ʒ� �ڵ忡�� * �� �ǹ̸� ������ ������
	// "Ŭ�����̸�::�̸�" �� ǥ������.. �̸��� �ǹ̴�
	// 1. �� �ϼ��� �ְ�   : static ��� ����Ÿ, enum �����
	// 2. Ÿ�� �ϼ��� �ִ� : typedef �Ǵ� using ��

//	Test::data  * p;	// ���ϱ� �ǹ�. ������ ����� ������� �ʴ´ٰ� ����ü���
//	Test::DWORD * p;	// ������ ���� ����.

	
	// "T::�̸�" : ������ "�̸�"�� ������ �ؼ�
	T::data  * p; // ok.
//	T::DWORD * p; // error

	typename T::DWORD * p; // ok.. T�� ������ �̸�(dependent name)��
							// Ÿ���� �̸����� �ؼ��� �޶�.
}


int main()
{
	Test t;
	foo(t);
}



