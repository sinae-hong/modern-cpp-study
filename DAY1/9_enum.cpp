// 9_enum - 32 page

enum DAYOFWEEK { sun = 0, mon = 1};

// 인자로 "요일"을 받고 싶다.
void foo(int dayofaweek) {}

int main()
{
//	foo(0);  // 0 : 일요일로 약속
	foo(sun);  

	int mon = 0;  // 에러 아님.
	foo(mon); // enum ? 지역변수
	foo(DAYOFWEEK::mon); // ok. 이렇게 사용하는것이 좋다.
	foo(sun);			// 그런데, C언어는 이것도 허용 - 나쁘다!!
						// scope 이름없이 사용가능하다. - "unscoped enum"
}





