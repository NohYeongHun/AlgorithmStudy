#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::cout;    using std::endl;
using std::string;
/*
    이것은 한 줄의 텍스트(예: 입력 문자열 )를 단어(예: 출력 벡터<string> )로 분할하는 목적을 가진 매우 간단한 프로그램
*/
int main(){

    vector<string> v;

    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        cout << v[i] << endl;
    
    for (vector<string>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
        cout << (*iter) << endl;
}
