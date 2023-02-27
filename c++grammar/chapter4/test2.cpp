#include<iostream>
#include <iomanip>
#include <ios>
using namespace std;

/*
    1부터 100까지 int 값의 제곱을 계산.
    첫 번째 값은 출력,
    두번째는 그 값의 제곱 출력,
    setw를 사용하여 출력 값이 열에 정렬되도록 함.
*/
int main(){
    for(int i = 1; i < 101; i++){  
        cout << "일반 값 = " << setw(5) << i << "\n";
        cout << "제곱 값 = " << setw(5) << i * i << "\n";
    }
}