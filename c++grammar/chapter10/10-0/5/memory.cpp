
// 이 함수느 ㄴ일부러 포인터 무효화
// 이것은 잘못된 예제를 보이기 위함. - 절대로 이렇게 하지 말기.
/*
    이 함수는 지역 변수 x의 주소를 리턴함.
    하지만 함수 리턴 시, x의 정의부가 포함된 블록도 끝나기 때문에 x는 해제됨.
    &x를 통한 포인터는 이제 무효화됨.
*/
#include<iostream>

using std::cout;
int* invalid_pointer()
{
    int x = 5;
    cout << "x = " << x << '\n';
    return &x; // 이렇게 하면 큰일
}

// 이 함수는 제대로 된 함수
int* pointer_to_static()
{
    static int x = 5;
    cout << "x = " << x << '\n';
    return &x;
}

int main(){

    int *p = invalid_pointer();
    cout << "invalid_pointer &x = " << *p << '\n';
    p = pointer_to_static();
    cout << "pointer_to_static &x = " << *p << '\n';
}