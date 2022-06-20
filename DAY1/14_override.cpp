// 14_override  - 44 page

class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// 가상 함수 재정의시 실수(오타)
	// => 하지만, 에러가 나지 않는다.
	// => 컴파일러는 새로운 가상함수를 만들었다고 생각하게 된다.
//	virtual void fooo() {}
//	virtual void goo(double a) {}
//	virtual void hoo() const  {}

	// C++11 부터는 가상함수 재정의시 "override" 를 붙이는것이 안전합니다
	virtual void fooo()        override {}
	virtual void goo(double a) override {}
	virtual void hoo() const   override {}

};


int main()
{
}

