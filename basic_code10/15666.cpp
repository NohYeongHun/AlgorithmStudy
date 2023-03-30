#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; 
int M;
int input[10];
int outArr[10];
int visited[10001];

void dfs(int cnt, int s)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << outArr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = s; i < N; i++)
    {
        outArr[cnt] = input[i];
        dfs(cnt + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int temp;
    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        if (visited[temp] == 0)
        {
            input[idx++] = temp;
            visited[temp] = 1;
        }
    }

    N = idx;
    sort(input, input + N);
    dfs(0, 0);

}