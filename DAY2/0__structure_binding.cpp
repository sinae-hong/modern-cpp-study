// 19_structure_binding - 52 page
#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0; // C++11 ���ʹ� �̷��� �ʱ�ȭ ����.
};
int main()
{
	Point3D p3d;

	// ��� ����� ������ �ʹ�.. util C++14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// C++17 ���� �Ʒ�ó�� ������ �ֽ��ϴ�
	auto[a1, a2, a3] = p3d; // auto a1 = p3d.x;
							// auto a2 = p3d.y;
							// auto a3 = p3d.z; �� �ǹ�!
//	int[b1, b2, b3] = p3d; // error. auto �� ����

//	auto[c1, c2] = p3d; // error. ������ ���ƾ� �Ѵ�.

	// ����ü �� �ƴ϶� �迭�� ����
	int arr[3] = { 1,2,3 };

	auto[d1, d2, d3] = arr; // ok     a,b = (1,2)

	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "������";

	// map�� pair�� �����մϴ�.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "ȭ����";

	m.insert(p); // �ᱹ m["tue"] = "ȭ����" �� ����

	// C++17 ������ map�� ��� ��� ������
	for (auto e : m) // ���⼭ e �� pair �Դϴ�
	{
		auto key = e.first;
		auto value = e.second;

	}
	// C++17 ���� �Ʒ� ó�� ��밡��
	for (auto[key, value] : m)
	{
	}

}

