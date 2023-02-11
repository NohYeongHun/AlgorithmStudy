#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < i; j++) cout << " ";
        for(int k = i * 2 + 1; k < n * 2; k++) cout << "*";
        cout << "\n";
    }
    for(int i = 1; i < n; i++){
        
        for(int j = i + 1; j < n; j++) cout << " ";
        for(int k = 0; k < i * 2 + 1; k++) cout << "*";
        cout << "\n";
    }

    return 0;
}