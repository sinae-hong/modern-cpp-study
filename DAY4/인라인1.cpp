// 인라인1.cpp - 136 page 이야기.

	   int add1(int a, int b) { return a + b; }
inline int add2(int a, int b) { return a + b; }

// 1. 인라인 치환은 컴파일 시간에 이루어 진다.
// 2. 인라인 함수라도 함수 포인터에 담아서 사용하면 치환 될수 없다.
int main()
{
	int n1 = add1(1, 2); // 호출 
	int n2 = add2(1, 2); // 치환

	int(*f)(int, int) = &add2;

//	if (사용자입력 == 1) f = &add1;

	f(1, 2); // 호출 ? 치환 ?
}