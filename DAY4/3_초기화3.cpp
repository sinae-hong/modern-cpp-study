int main()
{
	int  n1 = 3.4; // ok..
	char c1 = 500; 

	// prevent narrow - 56 page 중간부분
	int n2{ 3.4 };  // error. 
	int n3 = { 3.4 };  // error. 

	char c2{ 500 }; // error. 500 은 1byte 에 담을수 없다.

}