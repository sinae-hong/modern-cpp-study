// 8_nullptr - 29page

int main()
{
	// C++98 시절
	int  n1 = 0;
	int* p1 = 0;	// ok.   0 의 정체는 정수 
					//     하지만 0으로 암시적 변환 가능
//	int* p2 = 10;	// error

	// C++11 부터는 포인터 초기화시, 0 대신 nullptr사용하세요
	int* p3 = nullptr; // ok
//	int  n2 = nullptr; // error
}