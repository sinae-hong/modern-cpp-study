#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	Object(const Object&) {	std::cout << "copy" << std::endl;	}

	// move �迭 �Լ��� ���鶧��(move ������, move ���Կ�����)
	// �ǵ��� ���� ���� �����,
	// ���ܰ� ���ٰ�, �����Ϸ����� �˷� �ּ���
	Object(Object&&) noexcept
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

	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // �̼����� ������ �����غ��ô�.

	std::cout << "----------------" << std::endl;
}

