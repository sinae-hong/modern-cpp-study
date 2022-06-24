#include <iostream>
#include <algorithm>
#include <vector>

bool foo(int n) { return n % 3 == 0; }


class IsMod
{
	int value;
public:
	IsMod(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0;
	}
};



int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k;
	std::cin >> k;

	// 주어진 구간에서 처음 나오는 "k"의 배수를 찾고 싶다.
	// => 아래 처럼 "일반함수를 전달하면, main 안에 있는 지역변수 k를 같이 전달할수없다"
	// => "함수 + main의 지역변수" 를 같이 전달 할수 없을까 ?
//	auto ret1 = std::find_if(v.begin(), v.end(), foo );

//	IsMod f(k);
//	auto ret1 = std::find_if(v.begin(), v.end(), f );

	// 한번만 사용된다면, 임시객체로 전달하는 것이 좋다.
	// => 결국, IsMod 함수 객체를 사용하면
	// => "지역변수를 캡쳐 할수 있는 단항함수"를 만드는것
	auto ret1 = std::find_if(v.begin(), v.end(), IsMod(k) );
}











