#include <list>

// STL 에서 상속받는것은 좋은 코드는 아닙니다.
class MyList : public std::list<int>
{
public:
	void debug() {}  

	//C++98 시절의 코드
	// 인자로 받은것을 기반 클래스에 그대로 전달
//	MyList(int sz) : std::list<int>(sz) {}
//	MyList(int sz, int value) : std::list<int>(sz, value) {}
//	MyList(std::initializer_list<int> e) : std::list<int>(e) {}

	// C++11 부터는 생성자 상속을 사용하면 위 처럼할 필요 없습니다.
	using std::list<int>::list;

};

int main()
{
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
	MyList st3 = { 1,2,3 }; // 
}






