// 6_forwarding_reference1 - 아주 아주 중요!! - 93page

void f1(int&  r) {}
void f2(int&& r) {}

// 함수 인자로
// int&  : int 타입의 lvalue 만 받겠다는 의미
// int&& : int 타입의 rvalue 만 받겠다는 의미
// T&    : 임의 타입의 lvalue 만 받는 함수



// T&&   : 임의 타입의 lvalue/rvalue 를 모두 받을수 있는 함수
//		   "받을수 있다" 는 것은 "받을수 있는 함수를 생성" 한다는 것

// f4(n) 처럼 사용하면 f4(int& n) 이 생성	- 이때 T = int&   T&&=int&
// f4(10)	          f4(int&& n) 이 생성-     T = int    T&&=int&&

// 또한, 생성된 함수는 call by value 가 아닌 call by reference!!

// "T&&" 를 공식적으로 "forwarding reference" 라고 합니다.
// "universal reference" 라는 용어도 사용됩니다.(effective-C++ 책에서 제안한것)


template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 10;
	
	// 1. 사용자가 타입을 명시적으로 전달할때 어떤 함수가 생성되는지 생각해봅시다.
	f3<int>(n );	// T=int	T&=int&			생성된 함수 : f3(int&)
	f3<int&>(n );	// T=int&	T&=int& &		생성된 함수 : f3(int&)
	f3<int&&>(n );	// T=int&&	T&=int&& &		생성된 함수 : f3(int&)

	// 2. 사용자가 타입을 전달하지 않으면 
	//    컴파일러가 함수 인자로 보고 최대한 함수를 생성하려고 노력합니다
	f3(10); // error. 10 을 인자로 받는 함수는 만들수 없다.
	f3(n);  // T= int 결정됨
}






template<typename T> void f4(T&& a)
{
}
int main()
{
	int n = 10;

	// 1. 타입을 명시적으로 전달할때 생성되는 함수를 잘 생각하세요
	f4<int>(10);	// T=int		T&&=int&&		생성된 함수 : f4(int&&)
	f4<int&>(n);	// T=int&		T&&=int& &&		생성된 함수 : f4(int&)
	f4<int&&>(10);	// T=int&&		T&&=int&& &&	생성된 함수 : f4(int&&)

	// 2. 타입을 명시적으로 전달하지 않으면 어떻게 될지 잘 생각해 보세요
	// => 컴파일러는 함수를 생성하기 위해 최대한 노력합니다
	f4(n);	// int n 이므로 T= int 로 결정하면 f4(int&&) 가 생성됨 - 이경우 error
			// 그런데, T=int& 로 결정하면 f4(int&) 가 생성되므로 에러 아님!
			// 결국, 이경우 T = int& 로 결정됨.

	f4(10);// T=int 로 결정, 그런데 인자는 T&& 이므로 최종 함수는 f4(int&&)
}