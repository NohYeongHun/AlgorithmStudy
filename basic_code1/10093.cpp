#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a;
    long long b;
    long long r1, r2;

    cin >> a >> b;

    long long right, left;
    
    if (b >= a) right = b, left = a;
    else right = a, left = b;

    r1 = abs(b - a);
    if (r1 > 1){
        cout << r1 - 1 << "\n";
        for(long long num = left + 1; num < right; num++){
            cout << num << " ";
        }
    } 
    else {
        cout << 0 << "\n";
    }
    

    return 0;

}