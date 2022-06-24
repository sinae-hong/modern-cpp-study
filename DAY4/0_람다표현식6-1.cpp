#include <functional>

template<typename T> void f1(T f)   { f(1, 2);}

template<typename T> void f2(T&& f) { f(1, 2);}

int main()
{
	std::less<int> f;
	// �Ʒ� ó�� ����߽��ϴ�. f1 �Լ��� � �����ɱ�� ?
	f1(f);					// f1(std::less<int> )
	f1(std::less<int>());	// f1(std::less<int> )

	f2(f);					// f1(std::less<int>& )
	f2(std::less<int>());	// f1(std::less<int>&& )

}