#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    
    
    string stringArr[T];
    for(int i = 0; i < T; i ++){
        cin >> stringArr[i];
    }

    for(string s : stringArr){
        list<char> L;
        list<char>::iterator cursor;
        cursor = L.begin();
        for (char c : s){
            if (c == '<'){
                if (cursor != L.begin()) cursor--;
            } 
            else if (c == '>'){
                if (cursor != L.end()) cursor++;
            } 
            else if (c == '-'){
                if (cursor != L.begin()){
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else{
                L.insert(cursor, c);
            }

            
        }
        for(list<char>::iterator res = L.begin(); res != L.end(); res++){
            cout << *res;
        }
        
        cout<<"\n";
    }

    return 0;
}