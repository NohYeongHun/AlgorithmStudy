#include<iostream>
#include<bits/stdc++.h>

using namespace std;

stack<char> s;
string str;
int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cnt = 0;
    cin >> str;
    for(string::size_type i = 0; i!= str.size(); i++){
        
        if(str[i] == '('){
            // 괄호가 열릴 경우
            s.push(str[i]);
        } else {
            // 닫힐 경우 
            if (str[i - 1] == '('){
                // case 1. 이전값이 '(' 인 경우
                s.pop();
                cnt += s.size();
            }
            else {
                // case 2. 이전 값이 ')' 인 경우
                cnt++;
                s.pop();
            }
        }
    }

    cout << cnt;

    return 0;

}