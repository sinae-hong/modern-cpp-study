#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
	std::string addr;
public:
	// 아래 코드일때 에러메세지 확인
	/*
	template<typename T1, typename T2>
	People(T1&& s1, T2&& s2)
		: name(std::forward<T1>(s1)), addr(std::forward<T2>(s2))  // ok.. 정답!
	{
	}
	*/
	// 생성자는 "반환타입이 없습니다."
	// enable_if 를 반환 타입자리에 사용할수 없습니다.
	// 이 경우는 "대부분 템플릿 인자" 에 적용합니다.
	template<typename T1, 
		     typename T2,
//	         typename T3  = std::enable_if_t< 조건 > >
			 typename     = std::enable_if_t< std::is_convertible_v<T1, std::string > &&
										     std::is_convertible_v<T2, std::string > > >
	People(T1&& s1, T2&& s2)
		: name(std::forward<T1>(s1)), addr(std::forward<T2>(s2))  // ok.. 정답!
	{
	}
};
int main()
{
	std::vector<int> v;
	std::string s1 = "kim";
//	People p1(s1, s1);
	People p1(s1, v);
}
















