class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// 함수 포인터로의 변환을 허용하기 위해 추가되는 함수
	using PF = int(*)(int, int);

	// 변환 연산자 함수
//	operator PF() { return &CompilerGeneratedName::operator() ; };  
				// => error. 멤버 함수의 주소는 일반함수 포인터와 호환되지 않는다.
				//			 static 멤버 함수는 일반함수 포인터와 호환된다.
				//          그런데, operator() 함수는 static 이 될수 없다 는 문법이 있다

	// 결론, 함수 포인터와의 호환을 위해 아래 함수도 추가됨
	static inline int _helper(int a, int b) { return a + b; }

	operator PF() { return &CompilerGeneratedName::_helper; };
};



int main()
{
	int v1 = 0, v2 = 0;

//	int(*f)(int, int) = [](int a, int b) {return a + b; };

	int(*f)(int, int) = CompilerGeneratedName(); 
						// 임시객체.operator 함수포인터타입() 
}












