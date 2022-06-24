// 6_enable_if1.cpp

// �ٽ� 1. ���ø� ���ڷ� Ÿ���� �ƴ� "��" �� �����Ҽ� �ֽ��ϴ�
//      2. ���ø� ������ ����Ʈ ���� "primary" ���� ǥ���մϴ�.
//         �κ� Ư��ȭ ������ ǥ���ϸ� �ȵ˴ϴ�.(��, primary ������ ����˴ϴ�.)

template<bool, typename T = void > struct enable_if
{
//	typedef  T type; // ���� ��Ÿ��
	using type = T;  // ���� ��Ÿ��
};
template<typename T> struct enable_if<false, T> 
{
};

int main()
{
	// �Ʒ� �ڵ忡�� �� ������ Ÿ���� ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2 �ε�, void�� �������� �ȵ�. error
	enable_if<false, int>::type n3; // "::type" �� ���ٴ� ����

	// �����ϸ�
	// 1. enable_if<true, Ÿ��>::type �� ����� "Ÿ��"
	// 2. enable_if<true>::type       �� ����� "void"

	// 3. enable_if<false, Ÿ��>::type �� ����� ?  "::type" ��ü�� ����
	// 4. enable_if<false>::type       �� ����� ?  "::type" ��ü�� ����
}

#include <type_traits> // �� �ȿ� "enable_if" �ֽ��ϴ�. C++ ǥ���Դϴ�.

template<typename T> void foo(T a)
{
	// T �� �����ؼ� ����ϸ� typename �ʿ�
	typename std::enable_if<true, T>::type n1;

	std::enable_if_t<true, T> n2;  // �̷��� �ϸ� ���� ����
}




