class CompilerGeneratedName
{
	int v1, v2;
public:
	CompilerGeneratedName(int a, int b) :v1(a), v2(b) {}

	inline int operator()(int a, int b) const { return a + b + v1 + v2; }

	using PF = int(*)(int, int);

	static inline int _helper(int a, int b) { return a + b + v1 + v2;} // ????
			// => static ��� �Լ��� "��� ����Ÿ" ���� �ȵ˴ϴ�
			// => �׷���, ĸ���� ����ǥ������ �� �Լ��� ����� �����ϴ�.
			// => �׷���, ĸ���� ����ǥ������ �Լ� ������ ��ȯ �ȵ˴ϴ�.

	operator PF() { return &CompilerGeneratedName::_helper; };
};

int main()
{
	int v1 = 0, v2 = 0;

	//	int(*f)(int, int) = [v1, v2](int a, int b) {return a + b + v1 + v2; };
	//								=> error

	int(*f)(int, int) = CompilerGeneratedName(v1, v2);

}












