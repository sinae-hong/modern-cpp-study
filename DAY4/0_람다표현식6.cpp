// 5_����ǥ����6
// ����ǥ������ ���ڸ� �޴� ��� - 143p �Ʒ� �κ�

// 1. �Լ� ������ ���
// => �������� ĸ���� ���� ǥ���� ������ ����.
// => foo �ȿ��� f ���� "�ζ��� ġȯ �ȵ�"
// void foo( int(*f)(int, int) ) {}

// 2. template - call by value
// => ��κ��� ��� �̷��� ���..
// => f() ���� �ζ��� ġȯ��.
// => ��κ� empty class �̰�, 1~2�� �������� ĸ���ص�, ���纻 ������� ���� ����.
// template<typename T> 
// void foo(T f) {	f(1, 2);}

// 3. template - call by lvalue reference
// => ����ǥ���� ��ü�� "�ӽð�ü(rvalue)" �̴�. T& �� ������ ����.
// template<typename T> 
// void foo(T& f) {  }

// 4. const lvalue reference
template<typename T>
void foo(const T& f) 
{
	f(1, 2); // f.operator()(1,2) �ε�. f�� ��� ��ü�̴�.
			 // ��� ��ü�� ��� ��� �Լ��� ȣ�Ⱑ���ϴ�.
			// f �� "mutable lambda" ��� �̷��� ȣ���Ҽ� ����.
}

// 5. forwarding reference
// => ���� ���.
// => ũ�Ⱑ ū �Լ���ü(������ ���������� ĸ�ĸ� ����ǥ���ĵ�)
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