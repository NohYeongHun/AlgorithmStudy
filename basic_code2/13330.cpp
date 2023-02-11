#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int s, y;

    int students[2][7] = {};

    for(int i = 0; i < n; i++){
        cin >> s >> y;
        students[s][y] += 1;
    }

    int temp;
    int answer = 0;
    for(int i = 0; i < 2; i++){
        for (int j = 1; j < 7; j ++){
            answer += students[i][j] / k;
            if (students[i][j] % k != 0) answer+= 1;
        }
    }
    cout << answer;

    return 0;
}