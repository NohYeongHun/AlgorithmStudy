#include<iostream>

using std::cout;
using std::endl;
int main(){
    

    int x = 5;
    // int 타입 포인터 p는 x의 주소를 가집니다. 
    // p는 x를 가리킵니다.
    int* p = &x;
    cout << "x = " << x << endl;
    
    // p를 통해 x의 값을 변경합니다.
    *p = 6;
    cout << "x = " << x << endl;
    return 0;

}