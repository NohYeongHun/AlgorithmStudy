#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;


    for(int i = 0; i < n; i++){
        for(int k = i + 1; k < n; k++) cout << " ";
        for(int j = 0; j < 1 + i * 2 ; j++) cout << "*";
        cout << "\n";
    }
    for(int i = 1; i < n; i++){
        for(int k = 0; k < i; k++) cout << " ";
        for(int j = i * 2 + 1;  j < n * 2; j++) cout << "*";
        cout << "\n";
    }
    return 0;
}