
// constexpr 함수 : 인자의 값을 컴파일 시간에 알수 있다면
//				   함수 실행도 컴파일 시간에 해달라는 것
constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;


	int arr1[ Factorial(5) ];  // ok.. 컴파일 시간에 Factorial(5)실행

//	int arr2[Factorial(n)];		// error. 배열에 크기는 컴파일 시간에 알아야 한다.
								//		  Factorial(n) 은 인자가 변수 이므로
								//		  실행시간
						
	int s2 = Factorial(n);		// ok. 실행시간에 Factorial(n) 실행

							// 실행시간 ? 컴파일 시간
	      int s3 = Factorial(5); // 컴파일러마다 다름. 대부분 실행시간
	const int s4 = Factorial(5); // 컴파일러마다 다름. 대부분 실행시간
	constexpr int s5 = Factorial(5); // 반드시 컴파일 시간에 해달라!!
}






