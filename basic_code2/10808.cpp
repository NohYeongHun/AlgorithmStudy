#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int temp[26];
    fill(temp, temp + 26, 0);

    for (char c : s){
        temp[c - 'a'] += 1;
    }

    for(int i = 0; i < 26; i++) cout << temp[i] << " ";



    return 0;
}