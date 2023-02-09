#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i = 1; i < n + 1; i ++){
        for(int k = i; k < n + 1; k++){
            cout << "*";
        }
        cout <<"\n";
    }

    return 0;
}