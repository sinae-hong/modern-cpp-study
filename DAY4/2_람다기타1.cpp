// 7_���ٱ�Ÿ1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// ��� ����Ÿ ĸ�� ?
//		auto f = [](int a) { return a + data; }; // error
//		auto f = [data](int a) { return a + data; }; // error

		// ��� ����Ÿ�� �����Ϸ��� "this" �� ĸ���ϸ� �˴ϴ�.
//		auto f = [this](int a) { return a + data; };  // ok
							// ��Ȯ���� "this->data" �� �´� ǥ���������,, ��ó���ص� �մϴ�.

		auto f = [this](int a) { data = 100; return a + data; }; // ok

		f(0); // data = 100 �� ����Ǵµ�, �� �ڽ��� �������Ÿ�� ����˴ϴ�.

		std::cout << data << std::endl; // 100


		// ������ �������� �ʰ� �ϰ�ʹ�.(��, ��� ��� ����Ÿ�� ���纻�� ����� ���)
		// => C++17 ���� �Ʒ� ǥ��� �����մϴ�.(*this ĸ��)
		auto f2 = [*this](int a) mutable { data = 100; return a + data; }; 
	}
};

int main()
{
	Test t;
	t.foo(); 
}

