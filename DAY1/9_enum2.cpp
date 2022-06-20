// 9_enum - 32 page

//enum DAYOFWEEK { sun = 0, mon = 1 };  // C 스타일
enum class DAYOFWEEK { sun = 0, mon = 1 };  // C++11 새로운 enum

// void foo(int dayofaweek) {} // 새로운 enum 사용못함
void foo(DAYOFWEEK dayofaweek) {} // ok.. C++11 부터는 이렇게

int main()
{
//	int n1 = mon; // error.. scope 이름 필요
//	int n2 = DAYOFWEEK::mon; // error.. int 타입 아님.

	DAYOFWEEK n3 = DAYOFWEEK::mon; // ok... 정확한 표기법

	foo(DAYOFWEEK::sun); // ok

//	foo(0);// error

	foo(static_cast<DAYOFWEEK>(4));

	// 권장하지는 않지만 int 값으로 변경하려면 캐스팅...
	int n4 = static_cast<int>(DAYOFWEEK::mon);

	

}





