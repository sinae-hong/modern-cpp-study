struct Point 
{
	int x, y; 
};

// ��� 1. call by value
// Ư¡ : ���纻�� �����ȴ�
//void foo(Point pt) {}

// ��� 2. const lvalue reference
// => ���纻 ���� lvalue, rvalue ��� ������ �ִ�.
// => C++98 ������ ����ϴ� ������ ���.
// => Ư¡, ���纻�� ������, ����Ű�� ������ "�����"�� �߰��ȴ�.
// void foo(const Point& pt) {}

// ��� 3. ����� ���� ��� �ް� �ʹ� => C++98 �ȵ�
// C++11 : 2���� �Լ��� �����Ѵ�.
//void foo(int&  r) {}
//void foo(int&& r) {}

// ��� 4. "forwarding reference" �� ����ϸ�
//			��� Ÿ�Կ� ���� �� 2���� �Լ��� �ڵ������Ҽ� �ִ�.
template<typename T>
void foo(T&& r)
{
}

int main()
{
	Point pt;

	// foo �Լ��� lvalue �� rvalue�� ��� ������ �ʹ�.
	foo(pt);
	foo(Point());
}
