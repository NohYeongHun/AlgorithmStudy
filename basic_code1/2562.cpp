#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int temp = -1;
    int maxIdx = -1;
    for(int idx = 1; idx < 10; idx++){
        cin >> n;
        if (temp < n){
            temp = n; 
            maxIdx = idx;
        } 
    }
    cout << temp << "\n";
    cout << maxIdx;

    return 0;
}