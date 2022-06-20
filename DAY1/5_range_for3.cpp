#include <iostream>
#include <vector>

struct Point3D
{
	int x, y, z;
	// 사용자 정의 타입(컨테이너)을 range-for 에 넣으려면
	// begin()/end()가 있으면 됩니다.
	int* begin() { return &x; }		// 1번째 요소의주소
	int* end()   { return &z + 1; } // 마지막 요소의 다음 주소 
};

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  // 될까요 ? 되게하려면 필요한 것은 ?
		std::cout << n << std::endl; 

}















