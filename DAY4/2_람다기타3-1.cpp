class CompilerGeneratedName
{
	int v1, v2;
public:
	CompilerGeneratedName(int a, int b) :v1(a), v2(b) {}

	inline int operator()(int a, int b) const { return a + b + v1 + v2; }

	using PF = int(*)(int, int);

	static inline int _helper(int a, int b) { return a + b + v1 + v2;} // ????
			// => static 멤버 함수는 "멤버 데이타" 접근 안됩니다
			// => 그래서, 캡쳐한 람다표현식을 이 함수를 만들수 없습니다.
			// => 그래서, 캡쳐한 람다표현식은 함수 포인터 변환 안됩니다.

	operator PF() { return &CompilerGeneratedName::_helper; };
};

int main()
{
	int v1 = 0, v2 = 0;

	//	int(*f)(int, int) = [v1, v2](int a, int b) {return a + b + v1 + v2; };
	//								=> error

	int(*f)(int, int) = CompilerGeneratedName(v1, v2);

}












