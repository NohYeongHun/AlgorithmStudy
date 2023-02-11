#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int x;

    cin >> n;
    int nums[100001];
    for(int i = 0; i < n; i++) cin >> nums[i];
    cin >> x;
    int answer[2000001];

    
    int cnt = 0;
    int temp;
    for (int i = 0; i < n; i++){
        temp = nums[i];
        if (answer[x - temp] == 1)cnt += 1;
        answer[temp] = 1;
    }
    cout << cnt;
    return 0;
}