#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n;
stack<char> s;
string sentence;
char temp;
int cnt;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cnt = 0;
    cin >> n;
    while(n--){
        cin >> sentence;

        if (sentence.size() % 2 != 0){
            continue;
        }

        for(string::size_type i = 0; i != sentence.size(); i++){
            temp = sentence[i];

            if(!s.empty() && s.top() == temp){
                s.pop();
            } else {
                s.push(temp);
            }
        }

        if (s.empty()) cnt++;

        while(!s.empty()){
            s.pop();
        }
    }

    cout << cnt;

    return 0;
}