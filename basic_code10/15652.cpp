#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int M;

vector<int> v;
void dfs(int N, int M, int s)
{
    if (M == 0)
    {
        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = s; i < N + 1; i++)
    {
        v.push_back(i);
        dfs(N, M - 1, i);
        v.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    dfs(N, M, 1);
}