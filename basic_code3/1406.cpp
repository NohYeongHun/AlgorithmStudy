#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int T;
    cin >> T;
    list<char> L;
    
    for (char c : s){
        L.push_back(c);
    }

    list<char>::iterator cursor = L.end();
    char temp;
    
    for (int i = 0; i < T; i++){
        cin >> temp;
        if (temp == 'P'){
            char addChar;
            cin >> addChar;
            L.insert(cursor, addChar);
        }
        if (temp == 'L' && cursor != L.begin()) cursor--;
        if (temp == 'D' && cursor != L.end()) cursor++;
        if (temp == 'B' && cursor != L.begin()){
            cursor--;
            cursor = L.erase(cursor); 
        }
        
    }

    for (list<char>::iterator res = L.begin(); res!= L.end(); res++){
        cout << *res;
    }

    return 0;
}