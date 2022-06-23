// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// 멤버 데이타 캡쳐 ?
//		auto f = [](int a) { return a + data; }; // error
//		auto f = [data](int a) { return a + data; }; // error

		// 멤버 데이타에 접근하려면 "this" 를 캡쳐하면 됩니다.
//		auto f = [this](int a) { return a + data; };  // ok
							// 정확히는 "this->data" 가 맞는 표기법이지만,, 위처럼해야 합니다.

		auto f = [this](int a) { data = 100; return a + data; }; // ok

		f(0); // data = 100 이 실행되는데, 내 자신의 멤버데이타가 변경됩니다.

		std::cout << data << std::endl; // 100


		// 원본이 수정되지 않게 하고싶다.(즉, 모든 멤버 데이타의 복사본을 만들어 사용)
		// => C++17 부터 아래 표기법 가능합니다.(*this 캡쳐)
		auto f2 = [*this](int a) mutable { data = 100; return a + data; }; 
	}
};

int main()
{
	Test t;
	t.foo(); 
}

