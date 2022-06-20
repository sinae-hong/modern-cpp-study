// 19_structure_binding - 52 page
#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0; // C++11 부터는 이렇게 초기화 가능.
};
int main()
{
	Point3D p3d;

	// 모든 멤버를 꺼내고 싶다.. util C++14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// C++17 부터 아래처럼 꺼낼수 있습니다
	auto[a1, a2, a3] = p3d; // auto a1 = p3d.x;
							// auto a2 = p3d.y;
							// auto a3 = p3d.z; 의 의미!
//	int[b1, b2, b3] = p3d; // error. auto 만 가능

//	auto[c1, c2] = p3d; // error. 갯수가 같아야 한다.

	// 구조체 뿐 아니라 배열도 가능
	int arr[3] = { 1,2,3 };

	auto[d1, d2, d3] = arr; // ok     a,b = (1,2)

	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";

	// map은 pair를 보관합니다.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";

	m.insert(p); // 결국 m["tue"] = "화요일" 과 동일

	// C++17 이전에 map의 모든 요소 꺼내기
	for (auto e : m) // 여기서 e 는 pair 입니다
	{
		auto key = e.first;
		auto value = e.second;

	}
	// C++17 부터 아래 처럼 사용가능
	for (auto[key, value] : m)
	{
	}

}

