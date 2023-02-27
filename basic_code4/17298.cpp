#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n, val;
/*
    Ai의 오큰수는 오른쪽에 있으면서 
    Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다.
    그러한 수가 없는 경우에 오큰수는 -1이다.
*/
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    stack<int> s1, s2;
    list<int> ans;

    while(n--){
        cin >> val;
        s1.push(val);
    }

    int cur, injectVal;
    while(!s1.empty()){
        cur = s1.top();
        
        while(!s2.empty() && s2.top() <= cur){
            s2.pop();
        }

        if (!s2.empty() && s2.top() > cur){
            injectVal = s2.top();
        } else {
            injectVal = -1;
        }
        ans.push_front(injectVal);

        s1.pop();
        s2.push(cur);
    }

    for(list<int>::iterator iter = ans.begin(); iter != ans.end(); iter++){
        cout << *iter << " ";
    }


    return 0;
}