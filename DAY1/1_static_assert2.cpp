// static_assert : 반드시 필요한 문법은 아닙니다.
//				   하지만 사용하면 , 코드가 안전해 집니다.
//				  컴파일 시간에만 사용되므로
//					=> "기계어 코드가 생성되지 않습니다."
//					=> 실행시 오버헤드는 없습니다.

#include <iostream>
#include <type_traits> 

//#pragma pack(1)	// 구조체 align 을 1로 해 달라.
struct PACKET
{
	char cmd;
	int  data;
};

//static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
//				"error, packet has unexpected padding");

/*
int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/


template<typename T> void object_set_zero(T* p)
{
	// std::is_polymorphic<T>::value : T 타입이 가상함수가 있는지 조사
	//									=> 목요일날 배우는 기술
	static_assert(!std::is_polymorphic<T>::value, 
					"error, T has virtual function");

	memset(p, 0, sizeof(T)); // 안전한 코드 일까요 ? -> 가상 함수가 있는 class는 vtable 값을 변경하게 되어 위험함
}

class A
{
	int data;
	
	virtual void foo() {}
};
int main()
{
	A a;
	object_set_zero(&a);
}





