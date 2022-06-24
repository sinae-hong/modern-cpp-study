// 1_move14-1
#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
	std::string addr;
public:
	// 방법 1. 2개 만들자
//	void setName(const std::string& r) { name = r; }
//	void setName(std::string&& r) { name = std::move(r); }

	// 방법 2. forwarding reference

	// 핵심 : 코드가 아래와 같을때 main 처럼 사용시. 에러메세지 꼭 확인하세요
	// setName(vector& arg) 함수가 생성되고
	// "name = arg" 코드에서 에러 발생
	/*
	template<typename T>
	void setName(T&& arg)
	{
		name = std::forward<T>(arg);
	}
	*/
	template<typename T>
	
	std::enable_if_t< std::is_convertible_v<T, std::string> >
	setName(T&& arg)
	{
		name = std::forward<T>(arg);
	}

};

int main()
{  
	std::vector<int> v;

	People p;
	
	p.setName("kim");
	p.setName(v);

}















