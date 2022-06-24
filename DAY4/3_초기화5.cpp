#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	std::string s1("hello"); // string(const char* ) �����ڰ� �ִ�.
	hoo("hello");	// ok.. �������� �̻����� �ʴ�. �ߵȴ�.
	std::string s2 = "hello";	// �ᱹ ���ڵ尡 �ȴٴ°�
								// string(const char*) �� explicit �� �ƴϴ�.
//	s2 = "AA";// ���ڵ尡 ���Կ�����.. ������ �ֱ�
	//----------------------------------------------
	std::vector<int> v1(10);   // vector(int) �����ڰ� �ִ�.
	
	goo(10);	// �ȵǴ°��� ����. �׷���.. error

	std::vector<int> v2 = 10;	// �ᱹ ���ڵ尡 �ȵȴٴ� ��
								// vector(int) �����ڴ� explicit �̴�.
	

	//C++ ����Ʈ ������
	std::shared_ptr<int> sp1(new int);	// ok
	std::shared_ptr<int> sp2 = new int;	// error
	//	=> �����ڰ� explicit �̱� �����Դϴ�.


}





