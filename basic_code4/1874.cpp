#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// 입력 값을 담을 배열
int target[100001];

// 값을 임시로 넣어둘 스택
int stk[100001];

// 정답 배열
string answer[200002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 시작 값.
    int s = 1;
    int pointer = -1;
    // 타겟 값.
    int tp = 0, ap = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        // target 입력 받기.
        cin >> target[i];
    }


    while(s < n + 1 || tp < n){

        if(pointer > -1 && target[tp] == stk[pointer]){
            answer[ap++] = "-";
            pointer--;
            tp++;
        } else if (s == n + 1){
            break;
        } else {
            stk[++pointer] = s;
            answer[ap++] = "+";
            s++;
        } 
    }
    
    if (pointer > -1) cout << "NO";
    else {
        for(int i = 0; i < ap; i++){
            cout << answer[i] << "\n";
        }
    }
    

    return 0;
}