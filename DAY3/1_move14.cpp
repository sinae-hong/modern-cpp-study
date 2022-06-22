#include <iostream>
#include <string>
#include <vector>

// 106 page
class People
{
	std::string name;
	std::string addr;
public:
	// 함수 인자로 "call by value" 사용
	// => 인자 타입이 사용자 정의 타입이면 "복사본생성"에 따라 오버헤드가 있습니다.
	// => 이렇게 하지 말고 "const &" 로 하세요
//	void setName(std::string s) { name = s; }

	// setter 함수 인자를 "const reference" 로 받기 - C++98 시절 최고의 코드..
	// 그러나, C++11 부터는....
//	void setName(const std::string& r) { name = r; } // 항상 복사
//	void setName(const std::string& r) { name = std::move(r); } // 역시 항상 복사
														// r 이 const 이므로!!
														// const 는 move될수 없다

	// C++11 에서의 최고의 "setter 함수"
	void setName(const std::string& r) { name = r; }
	void setName(std::string&& r)      { name = std::move(r); }

	// 인자로 전달된것은 멤버에 보관하는 용도(setter) 가 아니라면
	// 그냥 한개 만들며 됩니다
	void fn(const std::string& s)
	{
		// s를 사용만 하는 경우
		std::cout << s << std::endl;
	}

	// 정리 
	// 1. 그냥 문자열을 받아서 사용만 하는 함수 => const std::string& 으로만 받으세요
	//										결국, 인자의 복사본을 만들게 되지 않으므로
	//										move 고려의 대상 아닙니다
	// 2. 인자로 받은 문자열을 다시 "멤버데이타" 등의 보관하는 경우, setName() 처럼
	// => 위 처럼 2개 만드세요.. => 최선의 코드
};

int main()
{
	People p;

	std::string s1 = "kim";
	std::string s2 = "kim";

	p.setName(s1);				// s자원 복사해서 사용해라
	p.setName(std::move(s2));	// s자원 이동해서 사용해라

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // "" 


	p.fn(s1);
	p.fn(std::move(s1));

	std::vector<std::string> v;

	std::string s2 = "aaa";

	v.push_back(s2);
	v.push_back(std::move(s2));
}






