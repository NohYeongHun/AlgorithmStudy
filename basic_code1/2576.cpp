#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nums[7];
    int min, temp, sum;

    min = 101;

    for (int i = 0; i < 7; i ++){
        cin >> nums[i];
    }

    sum = 0;
    for (int i = 0; i < 7; i ++ ){
        if (nums[i] %2 == 0) continue;
        else {
            sum += nums[i];
            if (min > nums[i]) min = nums[i];
        } 
    }

    if (min == 101) cout << -1;
    else cout << sum << "\n" << min;


    return 0;

}