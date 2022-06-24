#include <iostream>
#include <string>
#include <vector>

// 1. move 개념 : 자원의 복사가 아닌 자원의 이동
int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";
	std::string s3 = s1;		
	std::string s4 = std::move(s2);

	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl;



	std::vector<int> v1(10, 3); 
	std::vector<int> v2(10, 3);
	std::vector<int> v3 = v1;
	std::vector<int> v4 = std::move(v2);

	std::cout << v1.size() << std::endl; //
	std::cout << v2.size() << std::endl; //
}

