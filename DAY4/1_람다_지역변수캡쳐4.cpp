#include <iostream>
#include <vector>
#include <algorithm>

struct People
{
	// name, addr
	int age;
	People(int a) : age(a) {}
};

int main()
{
	std::vector<People> v;
	v.emplace_back(10); // v.push_back(People(10)) 의미.
	v.emplace_back(20);
	v.emplace_back(15);

	// 나이가 15살인 사람을 찾고 싶다. ?
	auto ret1 = std::find_if(v.begin(), v.end(), [](const People& p) { return p.age == 15; });

	int k = 10;
	// 나이가 k 인 사람을 찾고 싶다.
	// => 이럴때 지역변수 캡쳐 하면 됩니다.
	auto ret2 = std::find_if(v.begin(), v.end(), [k](const People& p) { return p.age == k; });
}







