#include <iostream>

class Object
{
public:
	Object() {}
	
	Object(const Object&) { std::cout << "copy" << std::endl; }	// ���� ������
	Object(Object&&)      { std::cout << "move" << std::endl; }	// �̵� ������
};
/*
template<typename T>
T&& move(T& obj)
{
	return static_cast<T&&>(obj);
}

*/

// �ٽ� 1. ���ø� ���鶧 T& �� ����, T&& �� ���� �� �����ϼ���
// T&  : lvalue �� �ްڴٴ°�
// T&& : lvalue, rvalue ��� �ްڴٴ°�

// ����, "const T&" �� ��� ������ ������, ����� �߰�
/*
template<typename T>
T&& move(T&& obj)
{
	static_cast<Object&&>(obj); // rvalue ĳ�����Դϴ�.

	static_cast<T&&>(obj); // rvalue ĳ���� �ƴմϴ�.
							// move ����, lvalue �� ������ lvalue ĳ����
							//				rvalue �� ������ rvalue ĳ�����Դϴ�
							// ��, �� ĳ������ "std::forward" �� ���� ��İ� ����!

	static_cast<std::remove_reference_t<T> &&>(obj); // �׻� rvalue ĳ����

	return static_cast<std::remove_reference_t<T> &&>(obj); // �׻� rvalue ĳ����
}
*/

// �Ʒ��ڵ尡 std::move �� ���� �Դϴ�.
template<typename T>
[[nodiscard]] constexpr std::remove_reference_t<T>&& move(T&& obj) noexcept
{
	return static_cast<std::remove_reference_t<T>&&>(obj); 
}


int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = std::move(o1);	// move
	Object o4 = static_cast<Object&&>(o2); // std::move �� ����, move

	std::cout << "----------" << std::endl;
	
	Object o5 = move(o1);	 // o1 �� lvalue �̹Ƿ� T= Object&
							 // static_cast<T&&>(obj);  => static_cast<Object& &&>(obj);

	Object o6 = move(Object()); // �ǵ��� �ұ�� ? �ȵǰ� �ұ�� ?
	std::cout << "----------" << std::endl;
}







