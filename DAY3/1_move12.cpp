#include <iostream>
#include <vector>
#include <string>
// cppreference.com ���� "string" �˻�
template<typename T>
class Object
{
	std::string name;
	T data;
public:
	Object() {}

	Object(const Object&) {	std::cout << "copy" << std::endl;	}

	// move �迭 �Լ��� ���鶧��(move ������, move ���Կ�����)
	// �ǵ��� ���� ���� �����,
	// ���ܰ� ���ٰ�, �����Ϸ����� �˷� �ּ���

	// f() noexcept        : ���ܰ� ����.
	// f() noexcept(true)  : ���ܰ� ����.
	// f() noexcept(false) : ���ܰ� �ִ�
	// std::is_nothrow_move_constructible<T>::value : T Ÿ���� move �����ڰ� ���ܰ� �ִ���
	//													������ ����.
	Object(Object&& obj) noexcept( std::is_nothrow_move_constructible<T>::value  )
		: name( std::move(obj.name) ), data( std::move(obj.data))
 	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // ���� ������
	Object o3 = std::move(o1); // ������ move ������
	Object o4 = std::move_if_noexcept(o3); // move �����ڿ� ���ܰ������� move �����ڻ��
											// ���� ���ɼ��� ������  ���� ������ ���

	// STL �� ���� �̵���, "std::move_if_noexcept" ���
	
	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // �̼����� ������ �����غ��ô�.

	std::cout << "----------------" << std::endl;
}

