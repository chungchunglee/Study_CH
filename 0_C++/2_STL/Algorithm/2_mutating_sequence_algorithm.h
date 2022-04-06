#pragma once
//변경 가능 시퀀스 알고리즘
/*
copy						원소들을 복사한다.
swap						시퀀스의 원소를 맞바꾼다.
transform				주어진 함수를 원소에 적용하고 얻은 리턴값으로 원소를 교체한다.
replace					주어진 값과 동일한 원소들을 다른 값으로 교체한다.
fill							원소들을 주어진 값으로 교체한다.
generate					원소들을 함수 호출을 통해 얻은 리턴 값으로 교체한다.
remove					주어진 값과 동일한 원소들을 제거한다.
unique					연속적으로 동일한 원소들을 제거한다.
reverse					원소들을 뒤집는다.
rotate						원소들을 회전한다.
random_shuffle	원소들의 순서를 랜덤시킨다.
partition					조건을 만족하는 원소들을 앞 쪽으로 재배치한다.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;
//copy(A,B,C) A~B를 C로 복사
void _copy();
//transform(A,B,C,Function); A~B 요소를 Function을 적용하고 C부터 값 붙여넣기
void _transform();
//replace(A,B,C,D); A~B 구간중 C값을 D로 변경
void _replace();
//fill(A,B,C); A~B 구간을 C로 할당
void _fill();
//reverse(A,B); 주어진 구간을 역순으로 재배치
void _reverse();
//random_shuffle(A,B); 주어진 구간의 요소를 무작위로 재배치
void _random_shuffle();