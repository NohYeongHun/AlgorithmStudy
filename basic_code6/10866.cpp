#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    deque<int> dq;
    string op;
    int temp;
    while(n--){
        cin >> op;
        if(op == "push_front"){
            cin >> temp;
            dq.push_front(temp);
        } else if (op =="push_back"){
            cin >> temp;
            dq.push_back(temp);
        } else if (op == "pop_front"){
            if (dq.empty()) cout << -1 << "\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
                
        } else if (op == "pop_back"){
            if (dq.empty()) cout << -1 << "\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (op == "size"){
            cout << dq.size() << "\n";
        } else if (op == "empty"){
            if(dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (op == "front"){
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        } else if (op == "back"){
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
    }


    return 0;
}