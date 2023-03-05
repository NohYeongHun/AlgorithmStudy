#include<iostream>
#include<algorithm>

using std::cout;
using std::copy;

// 이 함수의 호출자는 적절한 시기에 그 객체를 해제시켜야 할 책임이 있음.
int* pointer_to_dynamic()
{
    return new int(0);
}

char* duplicate_chars(const char* p)
{
    // 충분한 공간을 할당함. 널 때문에 하나 더 추가됨
    size_t length = strlen(p) + 1;
    char* result = new char[length];

    // 새로 할당된 공간에 복사하고, 그 첫째 요소에 대한 포인터를 리턴.
    copy(p, p + length, result);
    return result;
}

int main(){
    int* p = new int(42);
    ++*p;
    cout << "p val = " << *p << '\n';
    delete p;
    cout << "delete after p val= " << *p << '\n';

    const char* sp = duplicate_chars("Hello");
    cout << "*sp = " << *sp << '\n';

    // 포인터를 직접 출력시 C스타일 문자열로 처리되어 배열의 문자가 가리키는 첫 번째 문자부터 인쇄됨.
    // 문자열의 끝인 null문자 ('\0') 가 나타날때 까지 sp. 따라서 출력 sp = "Hello"기 표시
    cout << "sp = " << sp << '\n';
    delete sp;

    cout << "delete after sp = " << *sp << '\n';
    

}