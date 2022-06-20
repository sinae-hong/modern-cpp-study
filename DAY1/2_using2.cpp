#include <unordered_set>

//typedef std::unordered_set<int> useti;
//typedef std::unordered_set<double> usetd;

// std::unordered_set<int> 의 별명이 아니라(타입의 별명이 아니라)
// std::unordered_set      의 별명을 만들수 없을까 ?(템플릿의 별명)

//typedef std::unordered_set  USET; // 이렇게!!! 
								  // 그런데, 안된다.(error)

// typedef : 타입에 대한 별명
// using   : 타입에 대한 별명 + 템플릿에 대한 별명

using DWORD = int; // 타입에 대한 별명
using useti = std::unordered_set<int>; // 타입 별명

template<typename T>
using uset = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;
	useti s1;

	uset<int> s2;
	uset<double> s3;
}


