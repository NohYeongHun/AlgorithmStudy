#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    pair<int, string> x[N];

    for (auto &v : x) cin >> v.first >> v.second;

    stable_sort(x, x + N, [&](pair<int, string> a, pair<int, string> b){
        return a.first < b.first;
    });

    for (auto &v : x) cout << v.first << ' ' << v.second << '\n';


}