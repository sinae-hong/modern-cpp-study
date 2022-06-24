#include <iostream>
#include <type_traits>

// ���� : C++ ǥ�ؿ��� "remove_all_pointer" �� �����ϴ�.

template<typename T> struct remove_all_pointer
{
	using type = T;
};
template<typename T> struct remove_all_pointer<T*>
{
//	using type = T;
	// ��� ���.
	// ����� ����� "T=int" �� �ɶ�.. ���̻� �κ� Ư��ȭ ������ ������� �ʰ�
	//              primary ������ ����ϰ� �˴ϴ�.
	using type = typename remove_all_pointer<T>::type;
};

int main()
{
	// �Ʒ� traits �� �����͸� �Ѱ� ���� �մϴ�.
	std::remove_pointer<int***>::type n1; // int** n1

	// �����͸� ��� �����ϴ� ���� ����� ���ô�.
	remove_all_pointer<int***>::type n2; // int n2
}


