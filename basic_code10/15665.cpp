#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// 기존 풀이
// int N;
// int M;
// int board[10];
// int outArr[10];
// set<string> s;

// void dfs(int k)
// {
//     if (k == M)
//     {
//         string temp;
//         for (int i = 0; i < M; i++)
//         {
//             temp += to_string(outArr[i]);
//         }

//         if (s.find(temp) == s.end())
//         {
//             s.insert(temp);
//             for (int i = 0; i < M; i++)
//             {
//                 cout << outArr[i] << ' ';
//             }
//             cout << '\n';
//             return;
//         }
//         else
//         {
//             return;
//         }
        
//     }

//     for (int i = 0; i < N; i++)
//     {
//         outArr[k] = board[i];
//         dfs(k + 1);
//     }

// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> N >> M;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> board[i];
//     }

//     sort(board, board + N);
//     dfs(0);

// }

// up solving
int N; 
int M;
int board[10];
int outArr[10];
int visited[10001];


void dfs(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << outArr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        outArr[k] = board[i];
        dfs(k + 1);
    }


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    int temp;
    int idx = 0;
    // 중복 수열 제거
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        if (visited[temp] == 0)
        {
            visited[temp] = 1;
            board[idx++] = temp;
        }
    }
    sort(board, board + idx);
    N = idx;
    dfs(0);
}
