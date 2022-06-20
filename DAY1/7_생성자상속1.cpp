// 7_생성자상속1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:
	// C++98 : 생성자를 상속되지 않는다.
	// C++11 : 아래 처럼하면 상속됩니다
	using Base::Base;
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);
}
