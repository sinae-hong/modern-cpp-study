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
	void setName(const std::string& r) { name = r; }
	void setName(std::string&& r) { name = std::move(r); }
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

}















