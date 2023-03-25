#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int M;
int board[10];
vector<int> v; 
int visited[10];

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
    
    for (int i = s; i < N; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            v.push_back(board[i]);
            dfs(N, M - 1, i);
            v.pop_back();
            visited[i] = 0;
        }
        
    }

}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    sort(board, board + N);
    fill(visited, visited + 10, 0);

    dfs(N, M, 0);

}