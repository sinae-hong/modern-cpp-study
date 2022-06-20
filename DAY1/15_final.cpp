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
	virtual void foo()      override final {}  // 더 이상 재정의 할수없다.
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

class Derived2 final : public Derived  // 더이상 파생 클래스 만들수 없다.
{
public:
	//virtual void foo()      override {}  // error.
	virtual void goo(int a) override {}
};

class Derived3 : public Derived2 // error
{
};
int main()
{
}
