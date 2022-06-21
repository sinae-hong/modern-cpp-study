// 4_rvalue - 87 page
int x = 0;
int  foo() { return x;}
int& goo() { return x; }


// lvalue : 등호에 양쪽에 모두 올수 있다.
//          이름이 있고, 단일식을 넘어서 사용가능
//			주소연산자로 주소를 구할수 있다.
//		    참조를 반환하는 함수

// rvalue : 등호의 오른쪽에만 올수 있다.
//			이름이 없고, 단일식에서만 사용가능
//			주소연산자로 주소를 구할수 없다
//		    값를 반환하는 함수
//          literal(10, 3.4 등), 임시객체 
int main()
{
	int v1 = 10, v2 = 10;
	
	v1 = 20; // v1 : lvalue,  20 : rvalue
	10 = v1; // error. 10 은 rvalue이다.
	v2 = v1;

	int* p1 = &v1;
	int* p2 = &10; 

	foo() = 10;// error
	goo() = 10; // ok


	const int c = 10;
//	c = 20; // c 는 rvalue ? lvalue ?
			// 이름이 있고,메모리를 할당하고, 주소를 구할수 있다.
			// immutable 한 lvalue 이다.
			// C 언어에서는 rvalue로 구분합니다.(즉, 언어마다 다릅니다.)

	// 모든 RVALUE 는 상수이다. ?
	// => YES ? NO?	=> 답은 NO..
	// => 상수라서 왼쪽에 못오는게 아니라, 문법적으로 왼쪽에 올수 없는것!
	Point(1, 2).x = 10; // 에러지만
	Point(1, 2).set(1, 2);// 에러가 아니다.
}
int x = 10;
int* f1() { return &x; } // "f()" 자체는 rvalue
						// "int*" 라는 값으로 반환하므로

int*& f2() { return &x; } // error. & 를 반환하는데.. 주소는 rvalue 이므로
							// rvalue 는 참조로 담을수 없다.

int* p = &x;
int* f3() { return p; } // "int*" 타입의 값 반환 
						// "f3()" 은 rvalue
int*& f4() { return p; } // ok..  p 자체를 반환
							// "f4()" 는 lvalue
			
int main()
{
	int k = 0;
	f3() = &k; // error
	f4() = &k; // ok

	// "int*" 를 포인터라고 생각하지 마세요. "int*"라는 타입으로 생각하세요
}






f(); // rvalue








