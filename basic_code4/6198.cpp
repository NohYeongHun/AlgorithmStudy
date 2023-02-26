#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long
/*
    자신 빌딩 기준으로 오른쪽에 있으며
    자신보다 낮은 빌딩들이 있으면
    해당 하는 빌딩들의 옥상을 볼 수 있다.
    현재 빌딩에서 볼 수있는 옥상들의 개수를 모두 더하라.

    10 9 8 7 6 5
    1. 5
    2. 4
    3. 3
    4. 2
    5. 1
*/
int N;
ll ans;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;

    ll h;

    cin >> N;
    while(N--){
        cin >> h;
        while(!s.empty() && s.top() <= h){
            s.pop();
        }
        ans += s.size();
        s.push(h);
    }

    cout << ans;


    return 0;
}