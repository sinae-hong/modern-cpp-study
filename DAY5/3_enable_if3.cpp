#include <iostream>
#include <type_traits>

// std::enable_if< bool ��, Ÿ��>::type 

// �Ʒ� ���ø��� "������ �ƴϸ� ������ �ƴ϶�" "������� �ʰڴٴ� �ǹ�"
template<typename T> 
//typename std::enable_if< std::is_integral_v<T>, T>::type	// ������ ���̸� ::type �� "T" => ����Ÿ�� T
											    // ������ �����̸� "::type" �� ����. 

std::enable_if_t< std::is_integral_v<T>, T>    // _t ������ "::type" ǥ�� ����
gcd(T a, T b)
{
	return 0;  
}



double gcd(double a, double b)
{
	std::cout << "�Ǽ� ���� ����" << std::endl;
	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f);
}