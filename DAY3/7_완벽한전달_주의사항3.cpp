// 9_완벽한전달_주의사항3

// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 아래 함수 인자 "forwarding reference" 인가요 ?
	// 아래 함수 "함수 템플릿 인가요 ?" ==> 아닙니다. 
	// => 클래스 템플릿의 일반(템플릿이 아닌) 멤버 함수 입니다.
	void foo(T&& arg)
	{
	}

	// 아래 코드가 "forwarding reference" 입니다
	template<typename U>
	void foo(U&& arg)
	{
	}
};
int main()
{
	int n = 0;
	Test<int> t; // 이렇게 하는 순간 이미 T=int 입니다.
				 // void foo(int&& ) 로 이미 함수는 결정되었습니다
	
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n);  // error
	t.foo(10); // ok

	t.goo(n);	// ok
	t.goo(10);	// ok
}

