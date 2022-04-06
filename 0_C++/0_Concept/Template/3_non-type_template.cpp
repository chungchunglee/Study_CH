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
	cout << Char_HP << "에서 이벤트에 의해" << AddValue<int, EVENT_ADD_HP_VALUE>(Char_HP) << " 로 변경" << endl;
	
	float Char_EXP = 378.98f;
	cout << Char_EXP << "에서 이벤트에 의해" << AddValue<float, EVENT_ADD_EXP_VALUE>(Char_EXP) << " 로 변경" << endl;
	
	__int64 Char_MONEY = 34567890;
	cout << Char_MONEY << "에서 이벤트에 의해" << AddValue<__int64, EVENT_ADD_MONEY_VALUE>(Char_MONEY) << " 로 변경" << endl;
	return 0;
}