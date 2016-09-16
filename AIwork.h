#pragma once

#include <utility>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class AIwork {
    
public :
    AIwork(int type);   //생성자 : type은 AND 혹은 OR를 가질 수 있다.
    void do_work();     //Learning 하는 함수
    
private :
    FILE *fp;
    pair <int, int> x[4];   //x input들 예를 들어 x[0]의 경우 (0,0)이 들어간다.
    float w[3];             //w 의 set
    float theta;            //threshold값
    float delta_w[3];       //w의 변화량
    int correctset[4];      //정답
    int resultset[4];       //계산결과
    int error[4];           //error
    int op;                 //operator : AND 혹은 OR
    
private :
    AIwork (const AIwork& ai);
    int calculate(pair <int, int> x, float w[3]);   //Summation(wi*xi)
    float find_delta(int x, int err);
    int find_error(int r, int c);
    int errsum();
    void re_size();                                 //w값들을 재조정한다
};