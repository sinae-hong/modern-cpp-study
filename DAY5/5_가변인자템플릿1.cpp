// 7_�����������ø�1 - 225 page

// �������� �Լ� ���ø�
template<typename ... Ts> void foo(Ts ... args) {}

// �������� Ŭ���� ���ø�
template<typename ... Ts> class xtuple 
{
};

int main()
{
	xtuple<int> t1;
	xtuple<int, double> t2; // Ts : int, double �� �ֽ��ϴ�

	foo(1, 3.4, 'A'); // Ts : int, double, char 
					  // args : 1, 3.4, 'A'
					// foo(int, double, char) �Լ� ������.


}