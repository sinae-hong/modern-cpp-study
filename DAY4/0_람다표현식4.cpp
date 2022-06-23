// 5_람다표현식5
#include <iostream>

// 142 page
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 아래 한줄을 정확히 알아 두세요
	Point pt = Point(1, 2);

	// C++98 : 1. 우변의 임시객체를 만들고
	//		   2. 복사 생성자로 pt에 복사됨
	//  => 그런데, 대부분의 컴파일러가 최적화 하면서 "Point pt(1,2)" 와 동일한 기계어 생성       

	// C++11 : 1. 우변의 임시객체를 만들고
	//		   2. Move생성자로 pt에 복사됨
	//  => 그런데, 대부분의 컴파일러가 최적화 하면서 "Point pt(1,2)" 와 동일한 기계어 생성       

	// C++17 : 컴파일러 최적화 기술이 문법화 됨
	//		  "Point pt(1,2)" 와 동일한 의미
	//        "복사 생성자 생략 의무화" 라는 문법


	// 람다표현식의 활용
	// 1. STL 의 find_if 같은 알고리즘에 전달하기도 하고
	// 2. 아래 처럼 auto 변수에 담아서 함수 처럼 사용해도 됩니다.
	auto f = [](int a, int b) { return a + b; };
			  // class xxx{ operator()(int a, int b) { ....   }   };xxx();

	// 컴파일러가 만든 클래스가 "xxx" 라면
//	auto f = xxx(); // 인데
//	xxx f;          // 결국 이 의미.


	// 이제 f 는 정수 2개를 더하는 함수(함수객체) 라고 생각하면 됩니다.
	int n1 = f(1, 2);
	int n2 = f.operator()(1, 2); // 이 표기법이 된다는 점을 잘 알아 두세요(원리)

}










