#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<int> L = {1, 2};
    list<int>::iterator t = L.begin();
    L.push_front(10);
    cout << *t << "\n";
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // 10 6 1 2 5, t => 1
    for(auto i : L) cout << i << ' ';
    cout << "\n";
    t++; // t => 2
    cout << *t << "\n";
    t = L.erase(t); // 2 삭제, t => 5

    cout << *t << "\n";
    for(auto i : L) cout << i << ' ';
    cout << "\n";
    for(list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << ' ';

    return 0;
}