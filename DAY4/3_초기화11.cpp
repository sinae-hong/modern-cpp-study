// 1_�ʱ�ȭ11 - 65 page..
// aggregate initialization
// aggregate Ÿ�� : ��� ��Ҹ� {} �� �ʱ�ȭ �Ҽ� �ִ�Ÿ��
//				C ����ü, �迭 ��
struct Point
{
	int x, y = 0; // �̷��� �ʱⰪ�� ������ "trivial"�� �ƴѵ�.
					// aggregate Ÿ���� �˴ϴ�.

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

	void foo() {}	// ��� �Լ� �־ aggregate Ÿ���Դϴ�.

//	virtual void goo() {}	//�����Լ��� ������ aggregate �ƴ�.

//	Point() {}		// �� ������ ������ aggregate �ƴ�.

	Point() = default;
};


int main()
{
	Point p1;	
	Point p2 = { 1,2 };

//	Point p2(1, 2);
}