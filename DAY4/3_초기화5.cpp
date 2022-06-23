#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	std::string s1("hello"); // string(const char* ) 생성자가 있다.
	hoo("hello");	// ok.. 논리적으로 이상하지 않다. 잘된다.
	std::string s2 = "hello";	// 결국 이코드가 된다는것
								// string(const char*) 는 explicit 가 아니다.
//	s2 = "AA";// 이코드가 대입연산자.. 만든후 넣기
	//----------------------------------------------
	std::vector<int> v1(10);   // vector(int) 생성자가 있다.
	
	goo(10);	// 안되는것이 좋다. 그래서.. error

	std::vector<int> v2 = 10;	// 결국 이코드가 안된다는 것
								// vector(int) 생성자는 explicit 이다.
	

	//C++ 스마트 포인터
	std::shared_ptr<int> sp1(new int);	// ok
	std::shared_ptr<int> sp2 = new int;	// error
	//	=> 생성자가 explicit 이기 때문입니다.


}





