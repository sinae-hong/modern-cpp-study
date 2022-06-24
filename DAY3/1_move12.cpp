#include <iostream>
#include <vector>
#include <string>
// cppreference.com 에서 "string" 검색
template<typename T>
class Object
{
	std::string name;
	T data;
public:
	Object() {}

	Object(const Object&) {	std::cout << "copy" << std::endl;	}

	// move 계열 함수를 만들때는(move 생성자, move 대입연산자)
	// 되도록 예외 없이 만들고,
	// 예외가 없다고, 컴파일러에게 알려 주세요

	// f() noexcept        : 예외가 없다.
	// f() noexcept(true)  : 예외가 없다.
	// f() noexcept(false) : 예외가 있다
	// std::is_nothrow_move_constructible<T>::value : T 타입의 move 생성자가 예외가 있는지
	//													없는지 조사.
	Object(Object&& obj) noexcept( std::is_nothrow_move_constructible<T>::value  )
		: name( std::move(obj.name) ), data( std::move(obj.data))
 	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // 복사 생성자
	Object o3 = std::move(o1); // 무조건 move 생성자
	Object o4 = std::move_if_noexcept(o3); // move 생성자에 예외가없으면 move 생성자사용
											// 예외 가능성이 있으면  복사 생성자 사용

	// STL 은 버퍼 이동시, "std::move_if_noexcept" 사용
	
	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

