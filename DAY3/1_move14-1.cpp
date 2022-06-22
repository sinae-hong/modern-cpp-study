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
//	void setName(const std::string& r) { name = r; }
//	void setName(std::string&& r) { name = std::move(r); }

	// 107 page
	// forwarding reference 를 사용하면 string&, string&& 버전의 함수를 자동생성할수 있다.
	// => 즉, 위 2개의 함수를 자동생성할수 있다.
	template<typename T>
	void setName(T&& arg)
	{
		// 다음중 맞는 것은 ?
		name = arg;					// 1
		name = std::move(arg);		// 2
		name = std::forward<T>(arg);// 3

	}
};

int main()
{
	People p;

	std::string s1 = "kim";
	std::string s2 = "kim";

	p.setName(s1);				
	p.setName(std::move(s2));	

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // "" 

}















