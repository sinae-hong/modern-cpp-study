// decltype(auto) 보다 auto 반환이 더 적합한 경우가 많습니다

auto f1()			// int f1()
{
	int n = 10;
	int* p = &n;
	return *p;
}

decltype(auto) f2()	// int& f2()
{
	int n = 10;
	int* p = &n;
	return *p;
}

auto f3()  // int* f3()   이므로 ok..
{
	static int x[3] = { 1,2,3 };
	return x;
}

decltype(auto) f4() // int ( f4())[3]   즉, 배열을 반환하는 함수
{						//	그런데, 배열을 반환하는 함수는 컴파일 에러
	static int x[3] = { 1,2,3 };
	return x;
}

int main()
{

}