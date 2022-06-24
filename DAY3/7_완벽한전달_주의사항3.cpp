// 9_�Ϻ�������_���ǻ���3

// forwarding reference �̾߱�

template<typename T> class Test
{
public:
	// �Ʒ� �Լ� ���� "forwarding reference" �ΰ��� ?
	// �Ʒ� �Լ� "�Լ� ���ø� �ΰ��� ?" ==> �ƴմϴ�. 
	// => Ŭ���� ���ø��� �Ϲ�(���ø��� �ƴ�) ��� �Լ� �Դϴ�.
	void foo(T&& arg)
	{
	}

	// �Ʒ� �ڵ尡 "forwarding reference" �Դϴ�
	template<typename U>
	void foo(U&& arg)
	{
	}
};
int main()
{
	int n = 0;
	Test<int> t; // �̷��� �ϴ� ���� �̹� T=int �Դϴ�.
				 // void foo(int&& ) �� �̹� �Լ��� �����Ǿ����ϴ�
	
	// �Ʒ� �ڵ带 �����غ�����. ������ ������� ?
	t.foo(n);  // error
	t.foo(10); // ok

	t.goo(n);	// ok
	t.goo(10);	// ok
}

