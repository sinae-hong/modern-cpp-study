void f1(int* p) {}
void f2(char* p) {}

// std::nullptr_t 를직접 만들어 봅시다.

struct nullptr_t
{
	// 변환연산자는 반환 타입을 표기하지 않습니다.
//	operator int*() { return 0; }
//	operator char*() { return 0; }

	// 아래처럼 하면 모든 종류의 포인터로 암시적 형변환 가능합니다. 
	template<typename T>
	operator T*() { return 0; }
};
nullptr_t mynullptr;

int main()
{
	f1(mynullptr);	// 컴파일러가 mynullptr.operator int*() 를 찾게 됩니다.
					// "변환연산자" 라는 문법입니다.
	f2(mynullptr);	
}