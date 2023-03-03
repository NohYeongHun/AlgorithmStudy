#include<iostream>
#include<bits/stdc++.h>

using namespace std;


stack<int> e;
stack<char> s;
string temp;
int mul, ans;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> temp;

    // 유효성 검사
    for(string::size_type i = 0; i != temp.size(); i++){
        if(temp[i] == '(' || temp[i] == '['){
            s.push(temp[i]);
        } 
        else if(temp[i] == ')'){
            if (s.empty()){
                cout << 0;
                return 0;
            }
            else if (!s.empty() && s.top() == '(') {
                s.pop();
            }
            else if (!s.empty() && s.top() == '['){
                cout << 0; 
                return 0;
            }
        }
        else if(temp[i] == ']'){
            if (s.empty()){
                cout << 0;
                return 0;
            }
            else if (s.top() == '['){
                s.pop();
            } 
            else if (s.top() == '('){
                cout << 0;
                return 0;
            }
        }
    }

    if(!s.empty()){
        cout << 0;
        return 0;
    }

    mul = 1; ans = 0;
    for(string::size_type i = 0; i != temp.size(); i++){
        if(temp[i] == '('){
            mul *= 2;
        } else if (temp[i] == '['){
            mul *= 3;
        } else {
            if (temp[i] == ')'){
                if (temp[i - 1] =='('){
                    ans += mul;
                }
                mul /=2; 
            } else if (temp[i] == ']'){
                if (temp[i - 1] =='['){
                    ans += mul;
                }
                mul /= 3;
            }
        }
    }
    cout << ans;


}