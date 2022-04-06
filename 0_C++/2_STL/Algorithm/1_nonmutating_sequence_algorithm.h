#pragma once
//���� �Ұ� ������ �˰���
/*
for_each				�־��� �Լ��� �����ҿ� ����
find						���� �˻�
find_first_of		�־��� ���տ� ���ϴ� ������ ã��
adjacent_find	������ ���Ұ� ���� �̿��� �κ��� ã��
count					�־��� ���� ������ ���
mismatch			�� �������� ��ĵ�ؼ� �޶����� ������ ��ġ�� ã��
equal					�� �������� ��ĵ�ؼ� ��� ���Ұ� �������� �˻��Ѵ�.
search					���ϴ� �������� ã�Ƴ���.
search_n			�������� �־��� ���� ������ ���Ұ� ���������� �̾��� �������� Ž���Ѵ�.
find_end			�־��� �������� ��ġ�ϴ� �� ������ �κ��� ã�Ƴ���.
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//for_each(v.begin(), v.end(), PrintElement); ���� ���� ���� ��� ��ҿ� �Լ�ȣ��
void _for_each();
//find(v.begin(),v.end(), value); �־��� value�� ������ value�� ã�� �̸� �ݺ��� ���·� ���� - ó�� ������ �ٷ� ����
//find_if(v.begin(),v.end(), function); �־��� ������ �����ϴ� ���� ã�� �̸� �ݺ��� ���·� ���� - ó�� ������ �ٷ� ����
void _find();
void _find_if();
//count(v.begin(),v.end(), value); �־��� ���� ������ �־��� value�� ������ value�� ���� ����� ������ ����
//count_if(v.begin(),v.end(), function); �־��� ������ �����ϴ� ����� ������ ����
void _count();
void _count_if();
//equal(iter A, iter B, iter C); A~B ���� �� ������ C~ ��ġ�ϴ��� bool�� ��ȯ
void _equal();
//search(iter A, iter B, iter C, iter D); A~B�����ȿ� C~D������ �����ϴ� ���� iterator ��ȯ
void _search();