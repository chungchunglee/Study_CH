#pragma once
//변경 불가 시퀀스 알고리즘
/*
for_each				주어진 함수를 모든원소에 적용
find						선형 검색
find_first_of		주어진 집합에 속하는 값들을 찾기
adjacent_find	동일한 원소가 서로 이웃한 부분을 찾기
count					주어진 값의 개수를 계산
mismatch			두 시퀀스를 스캔해서 달라지는 원소의 위치를 찾기
equal					두 시퀀스를 스캔해서 모든 원소가 같은지를 검사한다.
search					원하는 시퀀스를 찾아낸다.
search_n			시퀀스에 주어진 값과 동일한 원소가 연속적으로 이어진 시퀀스를 탐색한다.
find_end			주어진 시퀀스와 일치하는 맨 마지막 부분을 찾아낸다.
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//for_each(v.begin(), v.end(), PrintElement); 일정 범위 안의 모든 요소에 함수호출
void _for_each();
//find(v.begin(),v.end(), value); 주어진 value과 동일한 value을 찾아 이를 반복자 형태로 리턴 - 처음 만나면 바로 리턴
//find_if(v.begin(),v.end(), function); 주어진 조건을 만족하는 값을 찾아 이를 반복자 형태로 리턴 - 처음 만나면 바로 리턴
void _find();
void _find_if();
//count(v.begin(),v.end(), value); 주어진 구간 내에서 주어진 value와 동일한 value을 갖는 요소의 개수를 리턴
//count_if(v.begin(),v.end(), function); 주어진 조건을 만족하는 요소의 개수를 리턴
void _count();
void _count_if();
//equal(iter A, iter B, iter C); A~B 까지 의 구간이 C~ 일치하는지 bool로 반환
void _equal();
//search(iter A, iter B, iter C, iter D); A~B구간안에 C~D구간이 존재하는 시작 iterator 반환
void _search();