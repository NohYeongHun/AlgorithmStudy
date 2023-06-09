#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    pair<int, int> x[N];
    for (int i = 0; i != N; ++i) cin >> x[i].first >> x[i].second;

    stable_sort(x, x + N, [&](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second < b.second;
        else 
            return a.first < b.first;
    });

    for (int i = 0; i != N; i++) cout << x[i].first << ' ' << x[i].second << '\n';

}