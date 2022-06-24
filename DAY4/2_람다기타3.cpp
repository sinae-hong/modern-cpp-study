class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// �Լ� �����ͷ��� ��ȯ�� ����ϱ� ���� �߰��Ǵ� �Լ�
	using PF = int(*)(int, int);

	// ��ȯ ������ �Լ�
//	operator PF() { return &CompilerGeneratedName::operator() ; };  
				// => error. ��� �Լ��� �ּҴ� �Ϲ��Լ� �����Ϳ� ȣȯ���� �ʴ´�.
				//			 static ��� �Լ��� �Ϲ��Լ� �����Ϳ� ȣȯ�ȴ�.
				//          �׷���, operator() �Լ��� static �� �ɼ� ���� �� ������ �ִ�

	// ���, �Լ� �����Ϳ��� ȣȯ�� ���� �Ʒ� �Լ��� �߰���
	static inline int _helper(int a, int b) { return a + b; }

	operator PF() { return &CompilerGeneratedName::_helper; };
};



int main()
{
	int v1 = 0, v2 = 0;

//	int(*f)(int, int) = [](int a, int b) {return a + b; };

	int(*f)(int, int) = CompilerGeneratedName(); 
						// �ӽð�ü.operator �Լ�������Ÿ��() 
}












