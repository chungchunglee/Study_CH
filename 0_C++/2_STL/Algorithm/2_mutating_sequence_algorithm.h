#pragma once
//���� ���� ������ �˰���
/*
copy						���ҵ��� �����Ѵ�.
swap						�������� ���Ҹ� �¹ٲ۴�.
transform				�־��� �Լ��� ���ҿ� �����ϰ� ���� ���ϰ����� ���Ҹ� ��ü�Ѵ�.
replace					�־��� ���� ������ ���ҵ��� �ٸ� ������ ��ü�Ѵ�.
fill							���ҵ��� �־��� ������ ��ü�Ѵ�.
generate					���ҵ��� �Լ� ȣ���� ���� ���� ���� ������ ��ü�Ѵ�.
remove					�־��� ���� ������ ���ҵ��� �����Ѵ�.
unique					���������� ������ ���ҵ��� �����Ѵ�.
reverse					���ҵ��� �����´�.
rotate						���ҵ��� ȸ���Ѵ�.
random_shuffle	���ҵ��� ������ ������Ų��.
partition					������ �����ϴ� ���ҵ��� �� ������ ���ġ�Ѵ�.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;
//copy(A,B,C) A~B�� C�� ����
void _copy();
//transform(A,B,C,Function); A~B ��Ҹ� Function�� �����ϰ� C���� �� �ٿ��ֱ�
void _transform();
//replace(A,B,C,D); A~B ������ C���� D�� ����
void _replace();
//fill(A,B,C); A~B ������ C�� �Ҵ�
void _fill();
//reverse(A,B); �־��� ������ �������� ���ġ
void _reverse();
//random_shuffle(A,B); �־��� ������ ��Ҹ� �������� ���ġ
void _random_shuffle();