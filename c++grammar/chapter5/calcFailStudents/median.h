#ifndef GUARD_MEDIAN_H
#define GUARD_MEDIAN_H
/*
    전처리기 변수 ifndef
    GUARD_median_h 가 어떻게 정의되어 있는지 체크.
    해당 이름이 정의되지 않았다면, 전처리기에게 이 지시문과 다음에
    나오는 #endif 사이에 있는 모든 내용을 처리하도록 요청함.
    이 이름은 전체 프로그램에서 유일한 이름이어야 함.
    이 이름은 다른 곳에서 중복되지 않도록 고유한 이름이어야함.
    GUARD_ <- 문자열을 덧붙임.
    이렇게 함으로써 다음 번에는 median.h가 아무것도 하지 않도록 함.
*/ 

// median.h 최종 버전
#include <algorithm>
#include <stdexcept>
#include <vector>
double median(std::vector<double>);  

#endif