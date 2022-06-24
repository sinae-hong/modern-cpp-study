#include <iostream>
using namespace std;

// 160 page
template<typename T, typename U> 
struct Object
{
	static void foo() { cout << "T, U" << endl; }
};

template<typename T, typename U>
struct Object<T*, U*>
{
	static void foo() { cout << "T*, U*" << endl; }
};

template<typename T, typename U>
struct Object<T*, U>
{
	static void foo() { cout << "T*, U" << endl; }
};

// �Ʒ� �ڵ尡 �ٽ� �Դϴ�.
// primary template �� ���ø� ���ڰ� 2�����  <typename T, typename U> struct Object;
// 1. ��ü ������ �ݵ�� 2�� �����ؾ� �մϴ� : Object<int, double> ó��
// 2. �κ�Ư��ȭ �ÿ� ������ ������ �ٸ��� �ֽ��ϴ�.

template<typename T>	// <== ���ڰ����� 2���� �ƴϴ�.
struct Object<T, T>		// <== ����� 2�� �־�� �մϴ�.
{
	static void foo() { cout << "T, T" << endl; }
};

// �Ʒ� ������ "partial specialization(�κ�Ư��ȭ)" �� �ƴ϶�
// "specialization(Ư��ȭ)" �Դϴ�.
template<>	
struct Object<int, short>		
{
	static void foo() { cout << "int, short" << endl; }
};

template<typename T, typename U, typename V>
struct Object<T, Object<U, V>>
{
	static void foo() { cout << "T, Object<U, V>" << endl; }
};


int main()
{
	// �Ʒ� ó�� ������ ����� ������.
	Object<int, double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int, int>::foo();    // T, T
	Object<int, short>::foo();   // int, short

	Object<short, Object<char, int>>::foo(); // T, Object<U, V> �� ����� ������
}



