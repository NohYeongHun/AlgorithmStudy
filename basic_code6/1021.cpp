#include<iostream>
#include<bits/stdc++.h>

using namespace std;

deque<int> dq;
int n, m;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> m;

    for(int i = 1; i < n + 1; i++){
        dq.push_back(i);
    }

    int cnt, cnt2, cnt3;
    int t, temp;
    cnt = 0;
    int size;
    while(m--){
        cin >> t;

        // 현재 위치
        int idx = find(dq.begin(), dq.end() - 1, t) - dq.begin();
        size = dq.size();
        // 1번 연산 가능여부
        if(idx == 0){
            dq.pop_front();
        }
        // 1번 연산이 안된다면?
        else{
            // 2번 연산 , 3번 연산.
            cnt2 = idx; cnt3 = size - idx;
            if (cnt2 <= cnt3){
                while(!dq.empty() && dq.front() != t){
                    temp = dq.front();
                    dq.pop_front();
                    dq.push_back(temp);
                    cnt++;
                }
            }else{
                while(!dq.empty() && dq.front() != t){
                    temp = dq.back();
                    dq.pop_back();
                    dq.push_front(temp);
                    cnt++;
                }
            }
            dq.pop_front();
        }
    }
    cout << cnt;

    return 0;
}