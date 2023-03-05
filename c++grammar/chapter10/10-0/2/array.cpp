#include<iostream>
/*
    배열을 어떻게 정의하건 배열과 포인터간에는 연관관계 존재
    배열의 이름에 무엇을 사용하던 간에, 그 이름은 배열의 처음 요소에 대한 포인터를 나타냄.
    coords를 배열로 정의했을 때, coords를 값으로 사용하면 
    그 배열의 처음 요소의 주소를 얻을 수 있음.
*/
using std::cout;
int main(){
    const size_t NDim = 3;
    double coords[NDim];
    *coords = 1.5;
    double* p;
    p = coords;

    cout << "coords[0] = " << coords[0] << '\n';
    cout << "coords[0] = " << coords[1] << '\n';
    cout << "*p = " << *p << '\n';

    for(int i = 0; i < NDim; i++){
        coords[i] = i + 0.5;
    }
    /*
        포인터의 산술 연산
        coords[n] == *(p + n)과 같음.
    */
    cout << '\n';
    cout << "coords[0] = " << coords[0] << '\n';
    cout << "coords[1] = " << coords[1] << '\n';
    cout << "coords[2] = " << coords[2] << '\n';
    cout << "*p = " << *p << '\n';
    cout << "*(p + 1) = " << *(p + 1) << '\n';
    cout << "*(p + 2) = " << *(p + 2) << '\n';


}