// 12_delete_function 37 page

int gcd(int a, int b) 
{
	// 최대 공약수 반환
	return 0;
}

//double gcd(double a, double b); // 핵심. 의도적으로 선언만 제공
								//	     구현 생략
						// 사용시 "의도적으로 링크 에러를내겠다는의도"

double gcd(double a, double b) = delete; // C++11 의 함수 삭제 문법
							// 사용시 "컴파일 에러"를 발생하겠다는 의도.

int main()
{
	gcd(10, 20);   // ok

	gcd(1.3, 3.4); // ??
}

// 그런데, 함수 삭제 문법은 일반함수 보다는
// 컴파일러가 만드는 special member function 을 삭제할때 사용