#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nums[5];
    int sum = 0, avg = 0, middle = 0, temp;
    for (int i = 0; i < 5; i++){
        cin >> nums[i];
    }

    for (int i = 0; i < 5; i ++){
        sum += nums[i];
    }

    for (int i = 0; i < 5; i ++){
        for (int j = i + 1; j < 5; j++){
            if (nums[i] > nums[j]){
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }

        }
    }

    cout << sum / 5 << "\n";
    cout << nums[2];
    
    return 0;

}