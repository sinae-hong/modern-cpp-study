// 1_�ʱ�ȭ10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// �Ʒ� 2���� �������� ?
	std::vector<int> v3(10, 2); // 10���� 2�� �ʱ�ȭ
								// v3.size() �� 10��

	std::vector<int> v4{10, 2}; // 2���� 10,2 �� �ʱ�ȭ
								// v4.size() �� 2��


	// �Ʒ� �ڵ忡�� ������ ?
//	std::vector<int> v5 = 10;	// error  explicit vector(int sz)								
//	std::vector<int> v6 = {10}; // ok              vector(std::initalizer_list<int>)


//	std::initializer_list<int> e = { 1, 3.4 }; // error
}




