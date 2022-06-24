// 5_람다표현식6
// 람다표현식은 인자를 받는 방법 - 143p 아래 부분

// 1. 함수 포인터 사용
// => 지역변수 캡쳐한 람다 표현식 받을수 없다.
// => foo 안에서 f 사용시 "인라인 치환 안됨"
// void foo( int(*f)(int, int) ) {}

// 2. template - call by value
// => 대부분의 경우 이렇게 사용..
// => f() 사용시 인라인 치환됨.
// => 대부분 empty class 이고, 1~2개 지역변수 캡쳐해도, 복사본 오버헤드 거의 없다.
// template<typename T> 
// void foo(T f) {	f(1, 2);}

// 3. template - call by lvalue reference
// => 람다표현식 자체는 "임시객체(rvalue)" 이다. T& 로 받을수 없다.
// template<typename T> 
// void foo(T& f) {  }

// 4. const lvalue reference
template<typename T>
void foo(const T& f) 
{
	f(1, 2); // f.operator()(1,2) 인데. f는 상수 객체이다.
			 // 상수 객체는 상수 멤버 함수만 호출가능하다.
			// f 가 "mutable lambda" 라면 이렇게 호출할수 없다.
}

// 5. forwarding reference
// => 좋은 방법.
// => 크기가 큰 함수객체(여러개 지역변수를 캡쳐를 람다표현식등)
template<typename T>
void foo(T&& f)
{
	f(1, 2);
}


int main()
{
	foo( [](int a, int b) { return a + b; } );
	foo( [](int a, int b) { return a - b; } );

	auto f1 = [](int a, int b) { return a + b; };
	foo(f1);

	int v1 = 10;
	auto f2 = [v1](int a, int b) { return a + b + v1; };
	foo(f2);

}