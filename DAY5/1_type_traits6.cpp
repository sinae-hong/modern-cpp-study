#include <iostream>

class Object
{
public:
	Object() {}
	
	Object(const Object&) { std::cout << "copy" << std::endl; }	// 복사 생성자
	Object(Object&&)      { std::cout << "move" << std::endl; }	// 이동 생성자
};
/*
template<typename T>
T&& move(T& obj)
{
	return static_cast<T&&>(obj);
}

*/

// 핵심 1. 템플릿 만들때 T& 로 할지, T&& 로 할지 잘 생각하세요
// T&  : lvalue 만 받겠다는것
// T&& : lvalue, rvalue 모두 받겠다는것

// 참고, "const T&" 도 모두 받을수 있지만, 상수성 추가
/*
template<typename T>
T&& move(T&& obj)
{
	static_cast<Object&&>(obj); // rvalue 캐스팅입니다.

	static_cast<T&&>(obj); // rvalue 캐스팅 아닙니다.
							// move 사용시, lvalue 를 보내면 lvalue 캐스팅
							//				rvalue 를 보내면 rvalue 캐스팅입니다
							// 즉, 이 캐스팅을 "std::forward" 의 동작 방식과 동일!

	static_cast<std::remove_reference_t<T> &&>(obj); // 항상 rvalue 캐스팅

	return static_cast<std::remove_reference_t<T> &&>(obj); // 항상 rvalue 캐스팅
}
*/

// 아래코드가 std::move 의 원리 입니다.
template<typename T>
std::remove_reference_t<T>&& move(T&& obj)
{
	return static_cast<std::remove_reference_t<T>&&>(obj); 
}


int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = std::move(o1);	// move
	Object o4 = static_cast<Object&&>(o2); // std::move 의 원리, move

	std::cout << "----------" << std::endl;
	
	Object o5 = move(o1);	 // o1 은 lvalue 이므로 T= Object&
							 // static_cast<T&&>(obj);  => static_cast<Object& &&>(obj);

	Object o6 = move(Object()); // 되도록 할까요 ? 안되게 할까요 ?
	std::cout << "----------" << std::endl;
}







