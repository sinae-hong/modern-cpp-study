
// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
	}

	// C++17 ���� �Ʒ� ó�� �����մϴ�
	// /std:c++latest     => ������Ʈ�޴�, �Ӽ� �޴�, C/C++, ����ٿ� �߰�
	// �ʱ�ȭ ������ ���� if ( init - if)
	if (int ret = foo(); ret == 0)
	{
	}

	// switch �� �˴ϴ�.
	switch (int n = foo(); n)
	{
	case 1: break;
	case 2: break;
	}
	
	// while �� �ɱ�� ???  �ȵ˴ϴ�.
	// �����ʿ䰡 �������ϴ�. "for" ���� �����Ƿ�!!
//	while (int cnt = 0; cnt < 10)
//	{
//		++cnt;
//	}
}







