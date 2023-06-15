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

    for (int i = 0; i != N; ++i)
        cin >> x[i].first >> x[i].second;

    stable_sort(x, x + N, [&](pair<int, int> a, pair<int, int> b){
        if (a.second == b.second ) {
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    });

    for (int i = 0; i != N; ++i)
        cout << x[i].first << ' ' << x[i].second << '\n';


}