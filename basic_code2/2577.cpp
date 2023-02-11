#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    int nums[10];
    fill(nums, nums + 10, 0);

    cin >> a;
    cin >> b;
    cin >> c;
    int temp = a * b * c;
    string s = to_string(temp);
    for (char c : s){
        nums[c - '0'] += 1;
    }

    for (int num : nums) cout << num << "\n";

    return 0;
}