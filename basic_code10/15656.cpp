#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int M;
int board[10];
vector<int> v;

void dfs(int N, int M)
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

    for (int i = 0; i < N; i++)
    {
        v.push_back(board[i]);
        dfs(N, M - 1);
        v.pop_back();
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    sort(board, board + N);
    dfs(N, M);

}