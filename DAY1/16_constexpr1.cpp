// 16_constexpr1

template<int N> class check {};

int main()
{
	int n = 10;
	const int c1 = 10;  // 컴파일 시간 상수(컴파일러가 값을 알고 있다.)
	const int c2 = n;	// 실행시간 상수(컴파일시에는 값을 모르고,
						//				실행할때 변경할수 없다는것)

	// 다음중 에러를 모두 고르세요
	// 배열, 템플릿인자 등은 컴파일할때 값(크기)를 알아야 한다.
	int arr1[10]; // ok
	int arr2[n ]; // error. 배열 크기로 변수 안됨.
	int arr3[c1]; // ok
	int arr4[c2]; // error

	check<n> ch1;// error
	check<c1> ch2;// ok
	check<c2> ch3;// error
}


