#include<string>
#include<iostream>

using std::string;
using std::cout;
int main(){
    /*
        문자열 리터럴은 실제로 const char의 배열임
        리터럴 안의 문자들의 개수보다 하나 더 많은 요소를 포함.
        여분 문자는 null 문자(null character 즉, '\0')로 
        컴파일러는 자동적으로 문자들의 끝에 이 문자를 추가해줍니다.
    */
    const char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    string s1(hello);
    string s2("Hello");
    string s3(hello, hello + strlen(hello));

    cout << "s1 = " << s1 << '\n';
    cout << "s2 = " << s2 << '\n';
    cout << "s3 = " << s3 << '\n';


}