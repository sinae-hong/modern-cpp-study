// 9_FOLD - 237 page
#include <iostream>
#include <vector>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	// (�ʱⰪ op ... op pack )
//	(std::cout << ... << args); // (((cout << 1) << 2) << 3)

//	(printv(args), ...);	// , �� ���� ������ �Դϴ�
							// pack �̸��� �ƴ϶� pack �� ����ϴ� ���ϵ� ����
							// ((( printv(1) ), printv(2) ), printv(3) )
	std::vector<int> v;

	(v.push_back(args), ...);

	// ���ۿ��� "C++ fold expression example" �ϸ� ��� �ִ� ���� �����ϴ�.
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



