#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int createAnagram(string front, string end){
    int comp1[26] = {};
    int comp2[26] = {};

    for (char c : front) comp1[c - 'a']++;
    for (char c : end) comp2[c - 'a']++;

    int cnt = 0;
    for (int i = 0; i < 26; i ++){
        if (comp1[i] >= comp2[i]) cnt += comp1[i] - comp2[i];
        else cnt += comp2[i] - comp1[i];
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string front, end;
    cin >> front;
    cin >> end;
    cout << createAnagram(front, end);

    return 0;
}