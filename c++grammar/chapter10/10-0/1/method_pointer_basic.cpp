#include <iostream>

using std::cout;
using std::endl;

int next(int n)
{
    return n + 1;
}

int main(){
    // fp를 역참조한뒤 그것을 int 인자를 사용하여 호출한다면 그 결과로 int타입 리턴.
    // 암묵적으로 fp는 int를 인자로 갖고 int를 결과로 리턴하는 함수에 대한 포인터임을 알 수 있음.
    int (*fp)(int);

    // fp는 int를 인자로 갖고 int를 결과로 리턴하는 함수인 next에 대한 주소값을 받음.
    // 두 문장은 동일함.
    // 함수의 이름은 그 자체로 함수의 주소값임.
    fp = &next;
    cout << "fp &next = " << &fp << '\n';
    fp = next;
    cout << "fp &next = " << &fp << '\n';
    // int type i 변수
    int i;

    i = 5;
    // i라는 int값이 존재할 때 fp를 사용하여 next 호출 시 i값이 증가하게됨.
    // 두 문장은 동일함.
    // 함수 호출시 포인터를 사용해서 호출한다는 것을 강조함.
    // 우리는 int 타입 fp 포인터가 가리키는 next 함수의 주소로 이동한뒤 i라는 int type 매개변수를 기입하고그 값을 i에 초기화한다.
    i = (*fp)(i);
    cout << "(*fp)(i) result = " << i << '\n';
    i = fp(i);
    cout << "fp(i) result = " << i << '\n';


}