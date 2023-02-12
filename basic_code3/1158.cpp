#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, count;
    cin >> n >> k;
    list<int> L;

    for(int i = 1; i < n + 1; i ++){
        L.push_back(i);
    }
    list<int>::iterator cursor = L.begin();

    list<int> answer;

    
    while (L.size()!= 1){
        for(int i = 0; i < k - 1; i++){
            cursor++;
            if(cursor == L.end()) cursor = L.begin();
        }
        answer.push_back(*cursor);
        cursor = L.erase(cursor);
        if (cursor == L.end()) cursor = L.begin();
    }
    cout << "<";
    for(list<int>::iterator ans = answer.begin(); ans != answer.end(); ans++){
        cout << *ans << ", ";
    }
    cout << *cursor<<">";

    return 0;
}