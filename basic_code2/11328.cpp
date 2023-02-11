#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string possibleCheck(string front, string end){
    int comp1[26] = {};
    int comp2[26] = {};

    for (char c : front) comp1[c - 'a']++;
    for (char c : end) comp2[c - 'a']++;

    for (int i = 0; i < 26; i ++){
        if (comp1[i] != comp2[i]) return "Impossible";
    }
    return "Possible";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string front, end;
    

    for(int i = 1; i < n + 1; i++){
        cin >> front >> end;
        cout << possibleCheck(front, end) << "\n";
    }



    return 0;
}