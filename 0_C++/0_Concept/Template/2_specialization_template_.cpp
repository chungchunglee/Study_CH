#include <iostream>

using namespace std;

//템플릿 사용
template <typename T1, typename T2> const T1& Max(const T1& a, const T2& b)
{
	cout << "Max(const T& a, const  T& b) 템플릿 버전 사용)" << endl;
	return a > b ? a : b;
}
//전문화시킨(Specialization)Max 함수
template <> const double& Max(const double& a, const double& b)
{
	cout << "Max(const double& a, const  double& b) 전문화 버전 사용)" << endl;
	return a > b ? a : b;
}

int main()
{
	double Char1_MP = 300;
	double Char1_SP = 400.25;
	double MaxValue1 = Max(Char1_MP, Char1_SP);
	cout << "MP와 SP 중 가장 큰 값은" << MaxValue1 << "입니다." << endl << endl;

	int Char2_MP = 300;
	double MaxValue2 = Max(Char2_MP, Char1_SP);
	cout << "MP와 SP 중 가장 큰 값은" << MaxValue2 << "입니다." << endl << endl;
	return 0;
}