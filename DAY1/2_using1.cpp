#include <unordered_set>

// C 스타일 코드 - typedef 
//typedef int DWORD;
//typedef void(*F)(); 

// C++11 부터는 위코드 대신 아래 처럼해도 됩니다.
// 아래 2줄은 위 2줄과 완벽히 동일합니다.
using DWORD = int;
using F = void(*)();

int main()
{
	DWORD n; // int n
	F     f; // void(*f)()  함수포인터 변수
}