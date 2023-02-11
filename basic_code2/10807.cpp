#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, temp, v;
    cin >> n;
    int nums[202];
    fill(nums, nums + 202, 0);

    for (int i = 0; i < n; i++){
        cin >> temp;
        nums[temp + 100] += 1;
    }
    cin >> v;
    
    cout << nums[v + 100];
    return 0;
}