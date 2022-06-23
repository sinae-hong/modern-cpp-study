// 3_초기화5-1

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

void f1(int   n) {}
void f2(Point p) {}

int main()
{
	int n1 = { 3 };

	f1(3);	// int n = 3
	f1({ 3 });	// int n = {3}

	f2({ 1,2 }); // ok.. Point pt = {1,2} 가 되므로

}








