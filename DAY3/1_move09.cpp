#include <iostream>
#include <string>

// 규칙 1. 사용자가 복사 계열과 move계열 함수를 모두 만들지 않으면
//	=> 컴파일러가 모두 제공해 준다.
//  => 컴파일러가 제공하는 복사 생성자는 모든 멤버를 복사해 준다.
//  => 컴파일러가 제공하는 Move 생성자는 모든 멤버를 Move해 준다.

// 규칙 2. 사용자가 복사 계열 함수만 제공하면
//  => 컴파일러는 move 계열 함수를 제공하지 않는다.
//  => std::move() 사용시 "복사 계열"함수 호출

//  => 이때 컴파일러에게 Move 를 만들어 달라고 하고 싶다면 "= default"로 요청

// 규칙 3. 사용자가 move 계열만 제공하면
//  => 복사 계열 함수는 "삭제" 된다. ("=delete")
//  => 복사 계열 함수를 사용하면 "삭제된 함수를 사용할수 없다" 고 에러 발생

//	=> 복사 계열을 컴파일러에게 요청하려면 "=default" 사용..

class Object
{
public:
	std::string name;
	Object(const std::string& s) : name(s) {}
	
//	Object(const Object& obj) : name(obj.name) { std::cout << "copy" << std::endl; }

	// 컴파일러에게 Move 생성자를 만들어 달라고 요청
//	Object(Object&&) = default;					// Move 생성자
//	Object& operator=(Object&&) = default;		// Move 대입 연산자
//	Object& operator=(const Object&) = default;	// 복사 대입 연산자

	Object(Object&& obj) : name(std::move(obj.name)) { std::cout << "move" << std::endl; }
};

int main()
{
	Object obj1("obj1");
	Object obj2("obj2");

	Object obj3 = obj1;				// 복사 생성자 호출
									// 모든 멤버 데이타가 복사
	Object obj4 = std::move(obj2);	// move 생성자 호출
									// 모든 멤버 데이타가 이동
	
	std::cout << obj1.name << std::endl; // "obj1"
	std::cout << obj2.name << std::endl; // ""
}

