// 9:25 분 부터 시작 합니다.
// https://github.com/codenuri/ssmoderncpp

#include <cassert>

// C++11 에서 컴파일 시간 assert 제공
static_assert( sizeof(int*) >= 8, "error, not 64 bit");

void foo(int age)
{
	// 주의사항. 변수 조사는 안됩니다.
	//		    컴파일 시간에 조사 가능한 것만 가능합니다.
	static_assert(age > 0, "error"); // error. 변수는 조사 안됨

	// 함수 인자를 바로 사용하지 말고
	// 인자값의 유효성을 먼저 확인해라
	assert(age > 0); // 실행시간 동작

	int* p = new int[age];

	delete[] p;
}
int main()    
{  
//	foo(-10);  // 실수로 음수 전달  
	foo(10);
}

// ctrl + F5 로 확인해보세요
