#include <iostream>

using namespace std;

template <typename T, int VAL> T AddValue(T const& CurValue)
{
	return CurValue + VAL;
}
const int EVENT_ADD_HP_VALUE = 50;
const int EVENT_ADD_EXP_VALUE = 30;
const int EVENT_ADD_MONEY_VALUE = 10000;

int main()
{
	int Char_HP = 250;
	cout << Char_HP << "���� �̺�Ʈ�� ����" << AddValue<int, EVENT_ADD_HP_VALUE>(Char_HP) << " �� ����" << endl;
	
	float Char_EXP = 378.98f;
	cout << Char_EXP << "���� �̺�Ʈ�� ����" << AddValue<float, EVENT_ADD_EXP_VALUE>(Char_EXP) << " �� ����" << endl;
	
	__int64 Char_MONEY = 34567890;
	cout << Char_MONEY << "���� �̺�Ʈ�� ����" << AddValue<__int64, EVENT_ADD_MONEY_VALUE>(Char_MONEY) << " �� ����" << endl;
	return 0;
}