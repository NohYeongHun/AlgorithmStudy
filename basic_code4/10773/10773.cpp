#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int stacks[100001] = {0};
int pointer = -1;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    int num;

    for(int i = 0; i < k; i++){
        cin >> num;
        if (num == 0) pointer--;
        else stacks[++pointer] = num;
    }

    int result = 0;
    for(int i = 0; i < pointer + 1; i++){
        result += stacks[i];
    }

    cout << result;

    return 0;
}