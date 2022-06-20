/*
// 아래 코드가 왜 에러인지 생각해 보세요 ?
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error. int 타입을 * 할수 없다.
	}
};
int main()
{
	A a;
}
*/

template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10; 
	}
};
int main()
{
	A<int> a;

	a.foo();
}
// 핵심 : "지연된 인스턴스화(lazy instantiation)"
//      => 클래스 템플릿에서 사용된 멤버 함수만 C++코드로 생성된다.
//		=> C++98 시절 부터 있던 내용









