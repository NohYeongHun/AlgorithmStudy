#include<iostream>
#include<bits/stdc++.h>

using namespace std;

stack<char> s;
int check;
string inputStr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        check = 1;
        char temp;
        getline(cin, inputStr);

        if(inputStr == "."){
            break;
        }
        for(string::size_type i = 0; i!= inputStr.size(); i++){
            temp = inputStr[i];
            if (temp == '(' || temp == '['){
                s.push(temp);
            } else if(temp == ')'){
                if(!s.empty() && s.top() == '('){
                    s.pop();
                } else {
                    check = 0;
                    break;
                }
            } else if(temp == ']'){
                if(!s.empty() && s.top() == '['){
                    s.pop();
                } else {
                    check = 0;
                    break;
                }
            }
        }

        if(!s.empty()){
            check = 0;
        }

        while(!s.empty()){
            s.pop();
        }

        if (check){
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
        
    }


    return 0;
}