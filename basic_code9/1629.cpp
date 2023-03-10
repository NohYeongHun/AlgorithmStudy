#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll func(ll a, ll b, ll c){
    
    if (b == 1) return a % c;
    if (b % 2 == 0){
        return func(a, b / 2, c) * func(a, b / 2, c) % c;
    }
    return (func(a, b / 2, c) * func(a, b / 2, c)) % c * a % c;
}

ll x, y, z;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y >> z;
    cout << func(x, y, z);

}