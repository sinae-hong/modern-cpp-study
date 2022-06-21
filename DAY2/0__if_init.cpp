
// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
	}

	// C++17 부터 아래 처럼 가능합니다
	// /std:c++latest     => 프로젝트메뉴, 속성 메뉴, C/C++, 명령줄에 추가
	// 초기화 구문을 가진 if ( init - if)
	if (int ret = foo(); ret == 0)
	{
	}

	// switch 도 됩니다.
	switch (int n = foo(); n)
	{
	case 1: break;
	case 2: break;
	}
	
	// while 도 될까요 ???  안됩니다.
	// 만들필요가 없었습니다. "for" 문이 있으므로!!
//	while (int cnt = 0; cnt < 10)
//	{
//		++cnt;
//	}
}







