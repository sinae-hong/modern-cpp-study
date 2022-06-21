// move �� ���� 99 page ~

// ���� ������ �ٽ� ����
class Point
{
	int x, y;
public:
	Point() {  }				// 1��
	Point(int a, int b) {  }	// 2��

	// ���� ������ ����� ������ ���ô�.
	// 1. call by value : ���� �����ڰ� ������ ȣ��Ǵ� ���
	//					  ������ ���� �߻�
//	Point(Point pt) {} // ���ڸ� ������ "Point pt = p3;" => Point pt(p3)
						// ��, �ٽ� ���� ������ ȣ��

	// 2. call by reference : ������ ���.. ������ ���� �ƴ�.
	// ���� : rvalue �� ������ ����.
	//       "��Ÿ��" ���� ��ȯ�ϴ� �Լ��� ��ȯ ���� ������ ����.
//	Point(Point& pt) {} // "Point& pt = p3"  

	// 3. ���� �����ڴ� "rvalue", "lvalue" �� ��� �޾ƾ� �Ѵ�.
	//    const - lvalue reference �ۿ� ����.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point foo()
{
	Point pt(1, 2);
	return pt;
}
int main()
{
	Point p1;		// 1�� ������ ���
//	Point p2(1);	// error. Point(int) ����� �����ڰ� ����.
	Point p3(1, 2);	// 2�� ������ ���
	Point p4(p3);	// Point(Point) ����� ������ �ʿ�
					//	=> ���� ������.
					//	=> ����ڰ� ������ ������ �����Ϸ��� ����
	Point ret = foo();
}



