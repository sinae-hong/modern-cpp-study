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
	// 아래 코드에서 * 의 의미를 생각해 보세요
	// "클래스이름::이름" 의 표현에서.. 이름의 의미는
	// 1. 값 일수도 있고   : static 멤버 데이타, enum 상수등
	// 2. 타입 일수도 있다 : typedef 또는 using 등

//	Test::data  * p;	// 곱하기 의미. 연산의 결과를 사용하지 않는다고 경고나올수도
//	Test::DWORD * p;	// 포인터 변수 선언.

	
	// "T::이름" : 무조건 "이름"을 값으로 해석
	T::data  * p; // ok.
//	T::DWORD * p; // error

	typename T::DWORD * p; // ok.. T에 의존한 이름(dependent name)을
							// 타입의 이름으로 해석해 달라.
}


int main()
{
	Test t;
	foo(t);
}



