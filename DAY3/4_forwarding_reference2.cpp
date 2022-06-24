struct Point 
{
	int x, y; 
};

// 방법 1. call by value
// 특징 : 복사본이 생성된다
//void foo(Point pt) {}

// 방법 2. const lvalue reference
// => 복사본 없이 lvalue, rvalue 모두 받을수 있다.
// => C++98 시절에 사용하던 유명한 기술.
// => 특징, 복사본은 없지만, 가리키는 참조가 "상수성"이 추가된다.
// void foo(const Point& pt) {}

// 방법 3. 상수성 없이 모두 받고 싶다 => C++98 안됨
// C++11 : 2개의 함수를 제공한다.
//void foo(int&  r) {}
//void foo(int&& r) {}

// 방법 4. "forwarding reference" 를 사용하면
//			모든 타입에 대해 위 2개의 함수를 자동생성할수 있다.
template<typename T>
void foo(T&& r)
{
}

int main()
{
	Point pt;

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point());
}
