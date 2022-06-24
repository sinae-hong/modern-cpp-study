// 7_가변인자템플릿1 - 225 page

// 가변인자 함수 템플릿
template<typename ... Ts> void foo(Ts ... args) {}

// 가변인자 클래스 템플릿
template<typename ... Ts> class xtuple 
{
};

int main()
{
	xtuple<int> t1;
	xtuple<int, double> t2; // Ts : int, double 이 있습니다

	foo(1, 3.4, 'A'); // Ts : int, double, char 
					  // args : 1, 3.4, 'A'
					// foo(int, double, char) 함수 생성됨.


}