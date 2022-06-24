using LREF = int&; // typedef int& LREF;
using RREF = int&&;
// 91 page
int main()
{
	int n = 10;

	LREF r1 = ? ;
	RREF r2 = ?;

	// reference collapsing
	LREF& r3 = ? ;
	RREF& r4 = ? ;
	LREF&& r5 = ? ;
	RREF&& r6 = ?;
}

template<typename T> void foo(T a)
{
	T& r = a;
}





