#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int nums[10];
    fill(nums, nums + 10, 0);
    string s = to_string(n);

    for (char c : s){
        nums[c - '0'] += 1;
    }
    nums[6] += nums[9];
    nums[9] = 0;

    int maxSet = 0;
    int temp = 0;
    for (int i = 0; i < 10; i++){
        temp = nums[i];

        if (i == 6){
            if (temp % 2 == 0) temp = temp / 2;
            else temp = temp / 2 + 1;
        }

        if (temp > maxSet) maxSet = temp;
    }
    
    cout << maxSet;
    return 0;
}