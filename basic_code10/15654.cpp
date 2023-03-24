#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int M;
int board[10];
vector<int> v;
int visited[10];

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
        if (visited[i] == 0)
        {
            visited[i] = 1;
            v.push_back(board[i]);
            dfs(N, M - 1);
            v.pop_back();
            visited[i] = 0;
        }
        
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
    fill(visited, visited + 10 ,0);
    dfs(N, M);


}