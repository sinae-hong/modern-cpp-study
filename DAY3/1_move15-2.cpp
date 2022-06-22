#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::string s1 = "kim";
	std::string s2 = "seoul";

	std::pair<std::string, std::string>  p1( s1, std::move(s2) );

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""
}















