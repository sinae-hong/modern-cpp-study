#include <iostream>

const int c1 = 10;
int const c2 = 20;

template<typename T>
class Base
{
public:
	// 아래 인자는 _arg_ 가 const 입니다.
	virtual void foo(const T arg) {	std::cout << "Base foo" << std::endl;	}

	virtual void goo(T const arg) { std::cout << "Base goo" << std::endl; }
	
	// 아래 2줄은 동일합니다
	// const T arg  => 이렇게 많이 사용하는데
	// T const arg  => 이 코드를 주장하는 사람도 많습니다.
};


class Derived : public Base<int*>
{
public:
	// 아래 코드는 _arg_ 는 const 아닙니다.
	// 아래 코드는 _arg_ 를 따라가면 const 입니다
	//virtual void foo(const int* arg) // override 

	// 아래 코드가 _arg_ 가 const 입니다
	virtual void foo(int* const arg)  override 
	{
		std::cout << "Derived foo" << std::endl;
	}

	virtual void goo(int* const arg) { std::cout << "Derived goo" << std::endl; }

};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" 나오게 가상함수 재정의해 보세요
				// override 붙이지 말고 해보세요.
}


