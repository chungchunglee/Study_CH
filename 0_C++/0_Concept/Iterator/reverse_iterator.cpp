#include <iostream>
#include <vector>
#include <algorithm>

#ifdef __riter__
void main()
{
	std::vector<int> v(8);

	for (int i = 0; i < v.size(); i++)
		v[i] = i + 1;
	
	//auto�� reverse �� �ޱ� ���ؼ��� rbegin ������� ����
	std::vector<int>::iterator iter;
	std::vector<int>::reverse_iterator riter;

	for (iter = v.begin(); iter != v.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	//rbegin , rend ����
	for (riter = v.rbegin(); riter != v.rend(); riter++)
		std::cout << *riter << " ";
	std::cout << std::endl;
}
#endif // 

void main()
{
	std::vector<int> v(8);

	for (int i = 0; i < v.size(); i++)
		v[i] = i + 1;

	std::vector<int>::reverse_iterator riter; //�б� ���� ����
	std::vector<int>::const_reverse_iterator criter; // �б⸸ ����
	
	//�Ϲ� for��
	for (riter = v.rbegin(); riter != v.rend(); riter++)
		std::cout << *riter << " ";
	std::cout << std::endl;
	
	for (criter = v.crbegin(); criter != v.crend(); criter++)
		std::cout << *criter << " ";
	std::cout << std::endl;

	//auto for��
	for (auto k = v.rbegin(); k != v.rend(); k++)
		std::cout << *k << " ";
	std::cout << std::endl;

	for (auto k = v.crbegin(); k != v.crend(); k++)
		std::cout << *k << " ";
	std::cout << std::endl;
}