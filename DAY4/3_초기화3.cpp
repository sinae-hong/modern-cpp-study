int main()
{
	int  n1 = 3.4; // ok..
	char c1 = 500; 

	// prevent narrow - 56 page �߰��κ�
	int n2{ 3.4 };  // error. 
	int n3 = { 3.4 };  // error. 

	char c2{ 500 }; // error. 500 �� 1byte �� ������ ����.

}