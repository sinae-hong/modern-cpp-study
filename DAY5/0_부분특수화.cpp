#include <iostream>
using namespace std;

// 160 page
template<typename T, typename U> 
struct Object
{
	static void foo() { cout << "T, U" << endl; }
};

template<typename T, typename U>
struct Object<T*, U*>
{
	static void foo() { cout << "T*, U*" << endl; }
};

template<typename T, typename U>
struct Object<T*, U>
{
	static void foo() { cout << "T*, U" << endl; }
};

// 아래 코드가 핵심 입니다.
// primary template 의 템플릿 인자가 2개라면  <typename T, typename U> struct Object;
// 1. 객체 생성시 반드시 2개 전달해야 합니다 : Object<int, double> 처럼
// 2. 부분특수화 시에 인자의 갯수가 다를수 있습니다.

template<typename T>	// <== 인자갯수가 2개가 아니다.
struct Object<T, T>		// <== 여기는 2개 있어야 합니다.
{
	static void foo() { cout << "T, T" << endl; }
};

// 아래 버전은 "partial specialization(부분특수화)" 가 아니라
// "specialization(특수화)" 입니다.
template<>	
struct Object<int, short>		
{
	static void foo() { cout << "int, short" << endl; }
};

template<typename T, typename U, typename V>
struct Object<T, Object<U, V>>
{
	static void foo() { cout << "T, Object<U, V>" << endl; }
};


int main()
{
	// 아래 처럼 나오게 만들어 보세요.
	Object<int, double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int, int>::foo();    // T, T
	Object<int, short>::foo();   // int, short

	Object<short, Object<char, int>>::foo(); // T, Object<U, V> 로 출력해 보세요
}



