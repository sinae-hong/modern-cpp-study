// 1_move14-1
#include <iostream>
#include <string>
#include <vector>

// 106 page
class People
{
	std::string name;
	std::string addr;
public:
	// 방법 1. 2개 만들자
//	void setName(const std::string& r) { name = r; }
//	void setName(std::string&& r) { name = std::move(r); }

	// 107 page
	// 방법 2. forwarding reference 를 사용하면 string&, string&& 버전의 함수를 자동생성할수 있다.
	// => 즉, 위 2개의 함수를 자동생성할수 있다.
	template<typename T>
	void setName(T&& arg)
	{
		// 다음중 맞는 것은 ?
//		name = arg;					// 1. 항상 복사 대입
//		name = std::move(arg);		// 2. 항상 rvalue 로 캐스팅, 즉, 항상 move
		name = std::forward<T>(arg);// 3. setName 의 인자로 rvalue 를 보냈다며 rvalue캐스팅
									//                     lvalue 를 보냈다면 lvalue캐스팅
	}

	// 권장 - setName()을 직접 구현해도 2개면 됩니다
	// => 방법1. 사용하세요
};

int main()
{
	People p;

	std::string s1 = "kim";
	std::string s2 = "kim";
	const std::string s3 = "kim";
	char char* s4 = "park";
	//							setName() 이 템플릿 이므로
	p.setName(s1);				// setName(std::string& ) 생성
	p.setName(s3);				// setName(const std::string& ) 생성
	p.setName(s4);				// setName(const char*& ) 생성
	p.setName(std::move(s2));	// setName(std::string&& ) 생성


	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // "" 

}















