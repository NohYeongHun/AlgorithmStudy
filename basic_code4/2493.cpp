#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
    높이가 같거나 큰 경우에만 신호를 수신할 수 있다.
    중요 
        => 스택의 최상단엔 현재 자신보다 큰 탑만 존재하면 된다.
        => 즉 자신보다 낮은 탑은 다 제거해도 상관 X;
        => 왼쪽에서 오른쪽으로 순회하므로 오른쪽으로 갈때마다 왼쪽에 있는 탑의 상태 값은 유지해줄 필요가없다.
*/
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> S;
    stack<int> I;
    int N;
    cin >> N;
    
    vector<int> v;

    int idx = 1;
    while(N--){
        int T;
        cin >> T;
        
        while(!S.empty() && S.top() < T){
            S.pop();
            I.pop();
        }

        if(!S.empty() && S.top() > T){
            cout << I.top() << " ";
        }else{
            cout << 0 << " ";
        }
        S.push(T);
        I.push(idx);
        idx++;
    }


    return 0;
}