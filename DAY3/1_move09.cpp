#include <iostream>
#include <string>

// ��Ģ 1. ����ڰ� ���� �迭�� move�迭 �Լ��� ��� ������ ������
//	=> �����Ϸ��� ��� ������ �ش�.
//  => �����Ϸ��� �����ϴ� ���� �����ڴ� ��� ����� ������ �ش�.
//  => �����Ϸ��� �����ϴ� Move �����ڴ� ��� ����� Move�� �ش�.

// ��Ģ 2. ����ڰ� ���� �迭 �Լ��� �����ϸ�
//  => �����Ϸ��� move �迭 �Լ��� �������� �ʴ´�.
//  => std::move() ���� "���� �迭"�Լ� ȣ��

//  => �̶� �����Ϸ����� Move �� ����� �޶�� �ϰ� �ʹٸ� "= default"�� ��û

// ��Ģ 3. ����ڰ� move �迭�� �����ϸ�
//  => ���� �迭 �Լ��� "����" �ȴ�. ("=delete")
//  => ���� �迭 �Լ��� ����ϸ� "������ �Լ��� ����Ҽ� ����" �� ���� �߻�

//	=> ���� �迭�� �����Ϸ����� ��û�Ϸ��� "=default" ���..

class Object
{
public:
	std::string name;
	Object(const std::string& s) : name(s) {}
	
//	Object(const Object& obj) : name(obj.name) { std::cout << "copy" << std::endl; }

	// �����Ϸ����� Move �����ڸ� ����� �޶�� ��û
//	Object(Object&&) = default;					// Move ������
//	Object& operator=(Object&&) = default;		// Move ���� ������
//	Object& operator=(const Object&) = default;	// ���� ���� ������

	Object(Object&& obj) : name(std::move(obj.name)) { std::cout << "move" << std::endl; }
};

int main()
{
	Object obj1("obj1");
	Object obj2("obj2");

	Object obj3 = obj1;				// ���� ������ ȣ��
									// ��� ��� ����Ÿ�� ����
	Object obj4 = std::move(obj2);	// move ������ ȣ��
									// ��� ��� ����Ÿ�� �̵�
	
	std::cout << obj1.name << std::endl; // "obj1"
	std::cout << obj2.name << std::endl; // ""
}

