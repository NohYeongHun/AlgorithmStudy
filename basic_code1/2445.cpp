#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        
        for(int j = 0; j < 1 + i; j++) cout << "*";
        for(int k = i * 2 + 1; k < n * 2 - 1; k++) cout << " ";
        for(int j = 0; j < 1 + i; j++) cout << "*";
        cout << "\n";
    }
    for(int t = 0; t < n * 2; t++) cout << "*";
    
    cout << "\n";

    for(int i = 1; i < n; i++){
        
        for(int j = i; j < n; j++) cout << "*";
        for(int k = 0; k < i * 2; k++) cout << " ";
        for(int j = i; j < n; j++) cout << "*";
        cout << "\n";
    }

    return 0;
}