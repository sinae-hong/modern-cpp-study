// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

void foo(std::initializer_list<int> e)
{
	// 꺼낼때는 STL 과 동일
	auto p1 = e.begin();
	autp p2 = e.end();

	// 또는 range-for
	for (auto n : e)
		std::cout << n << std::endl;
}
int main()
{
	// 우변의 데이타는 "스택에 차례대로 놓이게 됩니다."
	// initializer_list 는 {스택주소, 갯수} 를 관리합니다
	// 또는 {주소, 마지막다음주소} 로 관리할수도 있습니다.(컴파일러마다 다름)
	std::initializer_list<int> e = { 1,2,3,4,5 };
//	std::vector<int> v = { 1,2,3,4,5 }; // 데이타가 힙에 있습니다.

	foo(e);				// ok
	foo({ 1,2,3,4,5 }); // ok
	foo({ 1,2,3,4,5,6,7,8,9,10 }); // ok
		// 결론 : 함수가 std::initializer_list 를 인자로 가지면
		//        동일 타입의 객체를 몇개라도(가변) 받을수 있다.
}


