#include <iostream>

using namespace std;

//���ø� ���
template <typename T1, typename T2> const T1& Max(const T1& a, const T2& b)
{
	cout << "Max(const T& a, const  T& b) ���ø� ���� ���)" << endl;
	return a > b ? a : b;
}
//����ȭ��Ų(Specialization)Max �Լ�
template <> const double& Max(const double& a, const double& b)
{
	cout << "Max(const double& a, const  double& b) ����ȭ ���� ���)" << endl;
	return a > b ? a : b;
}

int main()
{
	double Char1_MP = 300;
	double Char1_SP = 400.25;
	double MaxValue1 = Max(Char1_MP, Char1_SP);
	cout << "MP�� SP �� ���� ū ����" << MaxValue1 << "�Դϴ�." << endl << endl;

	int Char2_MP = 300;
	double MaxValue2 = Max(Char2_MP, Char1_SP);
	cout << "MP�� SP �� ���� ū ����" << MaxValue2 << "�Դϴ�." << endl << endl;
	return 0;
}